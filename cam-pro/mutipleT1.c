#include<cstdlib>
#include<string>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>
#include<dirent.h>
#include <sstream>
#include <fstream>
#include <cassert>
#include <unistd.h>
#include <stdio.h>
#include <sys/stat.h>
#include <stdlib.h>
using namespace std;
void Getfilepath(const char *path, const char *filename,  char *filepath){
	strcpy(filepath, path);
	if(filepath[strlen(path) - 1] != '/')
        strcat(filepath, "/");
	strcat(filepath, filename);
	printf("path is = %s\n",filepath);
} 
bool DeleteFile(const char* path){
    DIR *dir;
    struct dirent *dirinfo;
    struct stat statbuf;
    char filepath[256] = {0};
    lstat(path, &statbuf);
    if (S_ISREG(statbuf.st_mode)){
        remove(path);
    }
    else if (S_ISDIR(statbuf.st_mode)){
        if ((dir = opendir(path)) == NULL)
            return 1;
        while ((dirinfo = readdir(dir)) != NULL){
            Getfilepath(path, dirinfo->d_name, filepath);
            if (strcmp(dirinfo->d_name, ".") == 0 || strcmp(dirinfo->d_name, "..") == 0)
            continue;
            DeleteFile(filepath);
            rmdir(filepath);
        }
        closedir(dir);
    }
    return 0;
}
struct individual{
	bool isAttend = false;
	string id;
};
const int N = 300;
void Test(string cmd){
    char line[N];
    FILE *fp;
    const char *sysCommand = cmd.data();
    if ((fp = popen(sysCommand, "r")) == NULL) {
        cout << "error" << endl;
        return;
    }
    while (fgets(line, sizeof(line)-1, fp) != NULL){
        cout << line ;
    }
    pclose(fp);
}
bool cmpi(individual a, individual b){
	return a.id < b.id;
}

int main(int argc, char* argv[]){
bool nolack = false;
/* get pictures from classroom */
Test("bash get1.sh");

/* P(data base [individuals]) P(group photo) */
cout<<"********** START: shell **********"<<endl;
    	Test("bash main3.sh");
cout<<"*********** END: shell ***********"<<endl;
/* V(actual in file) V(trash)*/

/* P(data base [individuals]) */
cout<<"** individuals should attend: from \"ini-base\": "<<endl;
	struct dirent *ptr;    
	DIR *dir;
	string PATH = "ini-base"; //modify this while change directory
	dir=opendir(PATH.c_str());
	vector<individual> student;
	int i = 0;
	individual bricklayer;
	while((ptr=readdir(dir))!=NULL){
        	if(ptr->d_name[0] == '.') continue;
		string brick = ptr->d_name;
		bricklayer.id=brick.substr(0, brick.rfind("."));
		student.push_back(bricklayer);
	}
	sort(student.begin(),student.end(), cmpi);
	for(auto s:student){
		cout<<s.id<<endl;
	}
	closedir(dir);
cout<<"come "<<student.size()<<" in total:"<<endl;
cout<<"======================================================"<<endl;
/* V(should)*/

/* P(actual in file) */
cout<<"** individuals actually attend from \"tmp/data.txt\": "<<endl;
	vector<string> data;
	string pathname = "tmp/data.txt";
	ifstream infile;
	infile.open(pathname.data()); 
	string suanz;
	string s;
	while(getline(infile, s)){
		data.push_back(s);
	}
	infile.close(); 
	sort(data.begin(),data.end());
	for(auto a : data){
		cout<<a;
		cout << endl;
	}
cout<<"======================================================"<<endl;
/* V(actual) */

/* P(actual) P(should) */
cout<<"******************* lack ******************"<<endl;
int mo = 0;
for(auto& s:student){
	if(data[mo] == s.id){
		s.isAttend = true;
		mo++;
	}
	else nolack = true;
}
for(auto s:student){
	if(!s.isAttend) cout<<s.id<<endl;
	else continue;
}
if(!nolack){cout<<"all people have come"<<endl;}
cout<<"****************** lack *******************"<<endl;
/* V(lack) */

/* P(trash) */
cout<<"********** delete directory **********"<<endl;
	const char* fileDirectory="tmp";
	DeleteFile(fileDirectory);
	if(remove(fileDirectory) == 0)
		cout<<"Removed Directory: "<<fileDirectory<<endl;
	else
        	perror("remove");
cout<<"********** delete  complete **********"<<endl;
	return 0;
/* V(recover clean) */
}
