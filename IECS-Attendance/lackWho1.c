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

void Getfilepath(const char *path, const char *filename,  char *filepath)
{
    strcpy(filepath, path);
    if(filepath[strlen(path) - 1] != '/')
        strcat(filepath, "/");
    strcat(filepath, filename);
	printf("path is = %s\n",filepath);
}
 
bool DeleteFile(const char* path)
{
    DIR *dir;
    struct dirent *dirinfo;
    struct stat statbuf;
    char filepath[256] = {0};
    lstat(path, &statbuf);
    
    if (S_ISREG(statbuf.st_mode))//判断是否是常规文件
    {
        remove(path);
    }
    else if (S_ISDIR(statbuf.st_mode))//判断是否是目录
    {
        if ((dir = opendir(path)) == NULL)
            return 1;
        while ((dirinfo = readdir(dir)) != NULL)
        {
            Getfilepath(path, dirinfo->d_name, filepath);
            if (strcmp(dirinfo->d_name, ".") == 0 || strcmp(dirinfo->d_name, "..") == 0)//判断是否是特殊目录
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

void Test(void){
    char line[N];
    FILE *fp;
    string cmd = "bash main3.sh";
    ////引号内是你的linux指令
    // 系统调用
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

int main(int argc, char* argv[]){
cout<<"********** START: execute shell **********"<<endl;
    	Test();
cout<<"*********** END: execute shell ***********"<<endl;
cout<<"get individuals should attend from  directory \"101individuals\"";
	struct dirent *ptr;    
	DIR *dir;
	string PATH = "101individuals";
	dir=opendir(PATH.c_str());
	vector<individual> student;
	int i = 0;
	individual bricklayer;
	while((ptr=readdir(dir))!=NULL){
        	if(ptr->d_name[0] == '.') continue;
		bricklayer.id=ptr->d_name;
		student.push_back(bricklayer);
	}
	cout<<"should come "<<student.size()<<" in total:"<<endl;
	for(auto s:student){
		cout<<s.id<<endl;
	}
	cout<<"=================="<<endl;
	closedir(dir);

/**
 * get individuals actually attend from file "tmp/data.txt"
 */
	vector<string> data;
	string pathname = "tmp/data.txt";
	ifstream infile;
	infile.open(pathname.data()); 
	string suanz;
	string s;
	while (getline(infile, s)) {
		data.push_back(s);
	}
	infile.close(); 
	for (auto a : data) {
		cout<<a;
		cout << endl;
	}
	const char* fileDirectory="tmp";
	DeleteFile(fileDirectory);
	if( remove(fileDirectory) == 0 )
		cout<<"Removed Directory: "<<fileDirectory<<endl;
	else
        	perror("remove");


	return 0;
}
