#include<iostream>
#include<vector>
#include<string>
#include<dirent.h>
using namespace std;
struct individual{
	bool isAttend = false;
	string id;
};
int main(int argc, char* argv[]){
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
	cout<<"==================";
	closedir(dir);

	return 0;
}
