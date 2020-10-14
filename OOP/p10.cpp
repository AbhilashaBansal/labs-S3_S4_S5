#include <iostream>
#include <iomanip>
using namespace std;

class Area{
	float ar;
	public:
	operator float (){
		return ar;
	}
	void area(int side){
		ar=(float)side*side;
	}
	void area(int ht, int base){
		ar = (ht*base)/2.0;
	}
	void area (float r){
		ar=r*r*(3.14);
	}
};

int main(){
	Area a,b,c;
	cout<<"Enter side of square: ";
	int s;
	cin>>s;
	a.area(s);
	float sq=a;

	cout<<"Area of square is: "<<sq;
	cout<<"\nEnter base and height of triangle: ";
	int base,h;
	cin>>base>>h;
	b.area(h,base);
	float tr=b;
	cout<<"Area of triangle is: "<<tr;

	cout<<"\nEnter radius of circle: ";
	float r;
	cin>>r;
	c.area(r);
	float ci=c;
	cout<<"Area of circle is: "<<ci;
}
