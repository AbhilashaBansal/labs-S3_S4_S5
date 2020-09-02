#include <iostream>
#include <cstring>
using namespace std;

class Student {
    string firstName;
    char surname;
    float total_marks;
    char gender;
    char result;
public:
    char grade(float total_marks){
        if(total_marks>=40){
            return 'P';
        }
        else{
            return 'F';
        }
    }
    void getData(){
        cout<<"Enter First Name: ";
        cin>>firstName;
        cout<<"Enter first letter of Surname: ";
        cin>>surname;
        cout<<"Enter Total Marks: ";
        cin>>total_marks;
        cout<<"Enter gender (M/F): ";
        cin>>gender;
        result = grade(total_marks);
    }
    void display(){
        cout<<"Here are your details: "<<endl;
        cout<<"Name: "<<firstName<<" "<<surname<<endl;
        cout<<"Gender: "<<gender<<endl;
        cout<<"Total Marks: "<<total_marks<<endl;
        cout<<"Result: "<<result<<endl;
        cout<<"Thank you!";
    }

};

int main(){
    Student s1;
    s1.getData();
    cout<<endl;
    s1.display();
    return 0;
}
