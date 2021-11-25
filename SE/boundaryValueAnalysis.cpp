#include <iostream>
#include <math.h>
#include <vector>
#include <set>
#include <iomanip>
using namespace std;

// Created by: ABHILASHA BANSAL

// BOUNDARY VALUE ANALYSIS

int main(){
	
	// Assumption: Length of sides of a triangle can lie between [1, 100]

	// Since number of input variables is 3, number of Boundary Value test cases will be 4*3+1 = 13

	int s[] = {1,2,50,99,100};
	int nominal = 50;

	set < vector<int> > test_cases;
	for(int i=0; i<3; i++){
		for(int j=0; j<5; j++){
			vector<int>v(3, nominal);
			v[i] = s[j];
			test_cases.insert(v);
		}
	}

	cout<<"The test cases are as follows: \n";
	cout<<"- - - - - - - - - - - - - - - - - - - - - - - - \n";
	cout<<left<<setw(20)<<"Test Case ID"<<setw(10)<<"Side 1"<<setw(10)<<"Side 2"<<setw(10)<<"Side 3"<<setw(25)<<"Expected Output\n";
	cout<<"\n";

	int id=1;
	for(auto it=test_cases.begin(); it!=test_cases.end(); it++){
		vector <int> v = *it;
		cout<<left<<setw(20)<<id++<<setw(10)<<v[0]<<setw(10)<<v[1]<<setw(10)<<v[2];
		if((v[0]+v[1]<v[2]) or (v[1]+v[2]<v[0]) or (v[2]+v[0]<v[1])){
			cout<<setw(25)<<"Not a triangle \n";
		}
		else{
			float ss = (v[0]+v[1]+v[2])/(2.0);
    		float area = sqrt(ss*(ss-v[0])*(ss-v[1])*(ss-v[2]));
    		cout<<setw(25)<<fixed<<setprecision(3)<<area<<"\n";
		}
	}


	return 0;
}
