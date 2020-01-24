#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <cassert> 
using namespace std;
int main(){
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
