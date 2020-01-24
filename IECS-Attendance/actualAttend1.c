#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <cassert> 
using namespace std;
void txt_to_vectorstring(vector<vector<string>>& res, string pathname)
{
	ifstream infile;
	infile.open(pathname.data());   //将文件流对象与文件连接起来 
	assert(infile.is_open());   //若失败,则输出错误消息,并终止程序运行 
	vector<string> suanz;
	string s;
	while (getline(infile, s)) {
		istringstream is(s); //将读出的一行转成数据流进行操作
		string d;
		while (!is.eof()) {
			is >> d;
			suanz.push_back(d);
		}
		res.push_back(suanz);
		suanz.clear();
		s.clear();
	}
	infile.close();             //关闭文件输入流 
}
int main(){
vector<vector<string>> data;
	txt_to_vectorstring(data, "tmp/data.txt");
	for (auto a : data) {
		for (auto b : a) {
			cout << b << " ";
		}
		cout << endl;
	}
	return 0;
}
