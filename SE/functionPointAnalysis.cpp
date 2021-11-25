#include <iostream>
using namespace std;
   

// Function Units
string functionUnits[5] = {
    "External Inputs",
    "External Outputs",
    "External Inquiries",
    "Internal Logical Files",
    "External Interface Files"
};

   
// Weight Factors
int weightFactors[5][3] = {
    { 3, 4, 6 },
    { 4, 5, 7 },
    { 3, 4, 6 },
    { 7, 10, 15 },
    { 5, 7, 10 },
};
   
   
// 14 factors
string aspects[14] = {
    "reliable backup and recovery required ?",
    "data communication required ?",
    "are there distributed processing functions ?",
    "is performance critical ?",
    "will the system run in an existing heavily utilized operational environment ?",
    "on line data entry required ?",
    "does the on line data entry require the input transaction to be built over multiple screens or operations ?",
    "are the master files updated on line ?",
    "is the inputs, outputs, files or inquiries complex ?",
    "is the internal processing complex ?",
    "is the code designed to be reusable ?",
    "are the conversion and installation included in the design ?",
    "is the system designed for multiple installations in different organizations ?",
    "is the application designed to facilitate change and ease of use by the user ?"
};
  
// CAF = Complexity Adjustment Factor
float calc_CAF(int factors[]){
    int F = 0;
    for(int i=0; i<14; i++){
        F += factors[i];
    }

    float CAF = 0.65 + (0.01*F);
    return CAF;
}

// UFP = Unadjusted Function Point
int calc_UFP(){
    int values[5][3];

    int UFP = 0;
   
    for(int i=0; i<5; i++){
        cout<<"Enter number of "<<functionUnits[i]<<" with low, medium & high complexity respectively: \n";
        cin>>values[i][0]>>values[i][1]>>values[i][2];
  
        UFP += values[i][0]*weightFactors[i][0];
        UFP += values[i][1]*weightFactors[i][1];
        UFP += values[i][2]*weightFactors[i][2];
    }
    
    return UFP;
}

int main(){
    int fourteen_factors[14];
    cout<<"Enter values for the 14 factors\n";
    for(int i=0; i<14; i++){
        cin>>fourteen_factors[i];
    }

    float CAF = calc_CAF(fourteen_factors); 
    int UFP = calc_UFP();

    cout<<"Complexity Adjustment Factor is: "<<CAF<<"\n";
    cout<<"Unadjusted Function Point is: "<<UFP<<"\n";

    int FP = CAF*UFP;
    cout<<"Function Point is: "<<FP<<"\n";

    return 0;
}