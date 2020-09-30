#include <iostream>
#include <math.h>
using namespace std;

class bank{
    float balance, rate;

    public:
    bank(float initial_balance, float r){
        balance = initial_balance;
        rate = r/100.0;
    }

    ~bank(){
        cout<<"Object destroyed.\n";
    }

    void deposit(){
        float amt;
        cout<<"Enter amount to be deposited: ";
        cin>>amt;
        balance += amt;
        cout<<amt<<"INR has been deposited successfully.\n";
        cout<<"Updated balance: "<<balance<<endl;
    }

    void withdrawal(){
        float amt;
        cout<<"Enter amount to be withdrawn: ";
        cin>>amt;
        if(balance<amt){
            cout<<"Not sufficient money in account!\n";
            cout<<"Balance is: "<<balance<<endl;
        }
        else{
            balance -= amt;
            cout<<amt<<"INR has been withdrawn from account.\n";
            cout<<"Updated balance: "<<balance<<endl;
        }
    }
    void compound(){
        int years;
        cout<<"Enter no of years: ";
        cin>>years;
        float interest = (balance * pow((1+rate), years)) - balance;
        cout<<"Compound interest for "<<years<<" years will be: "<<interest<<endl;
        cout<<"Total amount will be: "<<interest+balance<<endl;
    }

    float getBalance(){
        cout<<"Balance is: "<<balance<<endl;
        return balance;
    }

    void menu(){
        int n;
        cout<<1<<"     "<<"Deposit money\n";
        cout<<2<<"     "<<"Withdraw money\n";
        cout<<3<<"     "<<"Calculate Compound Interest\n";
        cout<<4<<"     "<<"Check balance\n";
        cout<<5<<"     "<<"Exit\n";
        cout<<"Enter your choice: ";
        cin>>n;
        switch (n){
            case 1: {
                deposit();
                break;
            }
            case 2: {
                withdrawal();
                break;
            }
            case 3: {
                compound();
                break;
            }
            case 4: {
                float b = getBalance();
                break;
            }
            case 5: {
                cout<<"Thanks for visiting!\n";
                break;
            }
            default: cout<<"Invalid option.\n";
        }
        if(n!=5){
            menu();
        }
        else{
            cout<<"Exitting ...\n";
        }
    }
};
int main(){
    float b, r;
    cout<<"Enter initial balance: ";
    cin>>b;
    cout<<"Enter rate of interest (in percentage) : ";
    cin>>r;
    bank B(b, r);
    B.menu();
    abc: cout<<"End of program\n";
    return 0;
}
