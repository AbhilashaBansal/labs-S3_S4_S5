#include <iostream>
using namespace std;

class Poly{
	double a, b, c;
	public:
	Poly(){
		a=b=c=0;
	}
	Poly(double x, double y, double z){
		a=x;
		b=y;
		c=z;
	}
	Poly operator + (Poly P2){
		Poly sum;
		sum.a = a+P2.getA();
		sum.b = b+P2.getB();
		sum.c = c+P2.getC();
		return sum;
	}

	double getA(){
		return a;
	}
	double getB(){
		return b;
	}
	double getC(){
		return c;
	}
};

ostream& operator <<(ostream& cout, Poly P){
	double a = P.getA(), b=P.getB(), c=P.getC();
	if(a){
		cout<<a<<"x^2 + ";
	}
	if(b){
		cout<<b<<"x + ";
	}
	cout<<c<<endl;
	return cout;
}

int main(){
	Poly q1(3, 4, -2);
	Poly q2(0, -4, 10);
	Poly sum;
	sum=q1+q2;
	cout<<q1<<q2<<"The sum of the two polynomials is: "<<sum;
	return 0;
}
