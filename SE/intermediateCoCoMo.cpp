#include <iostream>
#include <math.h>
using namespace std;

// Created by: ABHILASHA BANSAL

// INTERMEDIATE COCOMO

float constants[3][4]={3.2, 1.05, 2.5, 0.38,
					   3.0, 1.12, 2.5, 0.35,
					   2.8, 1.20, 2.5, 0.32};

char mode[][15]={"Organic", "Semi-Detached", "Embedded"};

char drivers[15][6] = {"RELY","DATA","CPLX","TIME","STOR",
					"VIRT","TURN","ACAP","AEXP","PCAP",
  					"VEXP","LEXP","MODP","TOOL","SCED"};

float costdrivers[15][6]={ 
	{0.75, 0.88, 1, 1.15, 1.40, -1},
	{-1, 0.94, 1, 1.08, 1.16, -1},
	{0.70, 0.85, 1,15, 1.30, 1.65},
    {-1, -1, 1, 1.11, 1.30, 1.66},
    {-1, -1, 1, 1.06, 1.21, 1.56},
    {-1, 0.87, 1, 1.15, 1.30, -1},
    {-1, 0.87, 1, 1.07, 1.15, -1},
    {1.46, 1.19, 1, 0.86, 0.71, -1},
    {1.29, 1.13, 1.00, 0.91, 0.82, -1},
    {1.42, 1.17, 1, 0.86, 0.70, -1},
    {1.21, 1.10, 1, 0.90, -1, -1},
    {1.14, 1.07, 1, 0.95, -1, -1},
    {1.24, 1.10, 1.00, 0.91, 0.82, -1},
    {1.24, 1.10, 1, 0.91, 0.83, -1},
    {1.23, 1.08, 1, 1.04, 1.10, -1}
};

void intermediateCOCOMO(int kloc){
	float effort, time, people;
	float EAF = 1.00;

	cout<<"Enter the ratings for the 15 cost drivers. \n";
	cout<<"(1:Very Low, 2:Low, 3:Nominal, 4:High, 5:Very High) \n";

	for(int i=0; i<15; i++){
		int val;
		cout<<drivers[i]<<"- \t";
		cin>>val;
		EAF *= (costdrivers[i][val-1]);
	}

	int mode_no;
	// organic
	if(kloc>=2 && kloc<=50) mode_no=0;	
	// semi-detached
	else if(kloc>50 && kloc<=300) mode_no=1;	 
	// embedded
	else mode_no=2;	 
	cout<<"The mode is "<<mode[mode_no];

	// Effort
	effort = (constants[mode_no][0]*pow(kloc, constants[mode_no][1]))*EAF;
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

	intermediateCOCOMO(kloc);
	cout<<"\n - - - - - - - - - - - - - - - - - - - - - - - - - - \n";
	return 0;
}
