#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(){

	ifstream f1("file1.txt");
	ofstream f2("file2.txt");
	if(!f1){
		cout<<"Error in opening file.\n";
	}
	else{
		while(f1){
			char ch=f1.get();
			if(ch!='\n' && ch!='\t' && ch!='\v' && ch!='\r' && ch!=' ' && ch!='\r\n'){
				f2.put(ch);
			}
		}
		cout<<"Task completed, check 'file2.txt' for result.\n";
	}
	return 0;
}
