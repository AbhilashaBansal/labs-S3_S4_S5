#include <iostream>
#include <math.h>
using namespace std;

// Created by: ABHILASHA BANSAL

// BASIC COCOMO

float constants[3][4]={2.4, 1.05, 2.5, 0.38,
					   3.0, 1.12, 2.5, 0.35,
					   3.6, 1.20, 2.5, 0.32};

char mode[][15]={"Organic", "Semi-Detached", "Embedded"};


void basicCOCOMO(int kloc){
	float effort, time, people;

	int mode_no;
	// organic
	if(kloc>=2 && kloc<=50) mode_no=0;	
	// semi-detached
	else if(kloc>50 && kloc<=300) mode_no=1;	 
	// embedded
	else mode_no=2;	 
	cout<<"The mode is "<<mode[mode_no];

	// Effort
	effort = constants[mode_no][0]*pow(kloc, constants[mode_no][1]);
	// Time
	time = constants[mode_no][2]*pow(effort, constants[mode_no][3]);
	// People required
	people = effort/time;

	cout<<"\nEffort = "<<effort<<" Person-Months";
	cout<<"\nDevelopment Time = "<<time<<" Months";
	cout<<"\nPeople Required = "<<ceil(people)<<" Persons";

	return;
}

int main(){
	int kloc;
	cout<<"- - - - - - - - - - - - - - - - - - - - - - - - - \n";
	cout<<"Enter the size of the project in KLOC: ";
	cin>>kloc;

	basicCOCOMO(kloc);
	cout<<"\n - - - - - - - - - - - - - - - - - - - - - - - - - - \n";
	return 0;
}
