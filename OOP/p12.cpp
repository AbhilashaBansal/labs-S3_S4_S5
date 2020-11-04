#include <iostream>
#include <string>
using namespace std;

class String{
	
	public:
	string a;
	String(){
		a="";
	}

	//assignment
	void operator = (string s){
		this->a = s;
	}
	void operator = (String obj){
		this->a = obj.a;
	}

	//comparison
	bool operator == (String obj){
		if(this->a==obj.a){
			return true;
		}
		return false;
	}
	bool operator > (String obj){
		if(this->a>obj.a){
			return true;
		}
		return false;
	}
	bool operator < (String obj){
		if(this->a<obj.a){
			return true;
		}
		return false;
	}

	//concatenation
	String operator + (String obj){
		String ans;
		ans.a = this->a + obj.a;
		return ans;
	}
};

ostream& operator << (ostream& cout, String obj){
	cout<<obj.a;
	return cout;
}

int main(){
	String s1, s2;
	//assignment
	s1 = "pine";
	s2 = "apple";

	//comparison
	if(s1==s2){
		cout<<"Both strings are equal.\n";
	}
	if(s1>s2){
		cout<<endl;
		cout<<s1<<" is greater than "<<s2<<endl;
	}
	if(s1<s2){
		cout<<endl;
		cout<<s1<<" is less than "<<s2<<endl;
	}

	//concatenation
	String s3 = s1+s2;
	cout<<"\nConcatenated string is: "<<s3<<endl;
	cout<<endl;
	return 0;
}




