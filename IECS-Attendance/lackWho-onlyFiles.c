#include<iostream>
#include<vector>
#include<string>
#include<dirent.h>
#include <sstream>
#include <fstream>
#include <cassert>
using namespace std;
struct individual{
	bool isAttend = false;
	string id;
};
int main(int argc, char* argv[]){
/**
 * get individuals should attend from  directory "101individuals"
 */
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

	return 0;
}
