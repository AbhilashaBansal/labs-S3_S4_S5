#include <iostream>
#include <iomanip>
using namespace std;

class Average{
	int a, b, c, d;
	public:
	Average(){
		a=b=c=d=0;
	}
	void getInput(){
		cout<<"Enter values of a, b, c and d.\n";
		cin>>a>>b>>c>>d;
	}
	friend float calculateavg(Average A);
};

float calculateavg(Average obj){
	float ans = (obj.a + obj.b + obj.c + obj.d)/4.0;
	cout<<"Average of the four numbers is "<<ans<<"."<<endl;
	return ans;
}

int main() {
    Average obj;
    obj.getInput();
    float avg = calculateavg(obj);
    return 0;
}
