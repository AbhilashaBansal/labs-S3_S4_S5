#include <iostream>
#include <fstream>
using namespace std;

bool check(string s){
	for(int i=0; i<s.length(); i++){
		if(s[i]!=' ') return true;
	}
	return false;
}

int main(){

	int lines_of_code = 0;
	int non_blank_loc = 0;
	ifstream f1("splitwise.cpp");

	string line;
	while(getline(f1, line, '\n')){
		lines_of_code++;
		if(check(line)) non_blank_loc++;
	}

	cout<<"Lines of code: "<<lines_of_code<<endl;
	cout<<"Non blank Lines of Code: "<<non_blank_loc<<endl;

	return 0;
}