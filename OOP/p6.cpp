#include <iostream>
#include <cstring>
using namespace std;

class Employee {
    int EmpNumber;
    string EmpName;
    public:
    void getData(){
        cout<<"Enter number: ";
        int no; 
        string name;
        cin>>no;
        
        cout<<"Enter name: ";
        cin.clear();
        cin.sync();
        cin.ignore();
        getline(cin, name);
        EmpNumber = no;
        EmpName = name;
    }
    void display(){
        cout<<"Employee Number: "<<EmpNumber<<endl;
        cout<<"Employee Name: "<<EmpName<<endl;
        cout<<endl;
    }
};
int main() {
    Employee E[10];
    int n;
    cout<<"Enter the total number of employees: ";
    cin>>n;
    for(int i=0; i<n; i++){
        E[i].getData();
    }
    for(int i=0; i<n; i++){
        E[i].display();
    }
    return 0;
}
