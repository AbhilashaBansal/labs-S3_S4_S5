#include <iostream>
using namespace std;

void swap_by_reference(int &a, int &b);

class Swap {
    int a;
    int b;
    public:
    // Swap(){
    //     a=b=0;
    // }
    void getdata(){
        cout<<"Enter the values : ";
        cin>>a>>b;
    }
    void swap_by_val(){
        a = a+b;
        b = a-b;
        a = a-b;
    }
    void display(){
        cout<<a<<" "<<b<<endl;
    }

    void swap_by_ref(){
        swap_by_reference(a, b);
    }
};

void swap_by_reference(int &a, int &b){
    a = a+b;
    b = a-b;
    a = a-b;
}

int main() {
    Swap S;
    S.getdata();
    int n;
    cout<<"Press 1 to swap by value and 2 to swap by reference: ";
    cin>>n;
    switch (n){
        case 1: {
            S.swap_by_val();
            cout<<"New values are: ";
            S.display();
            break;
        }
        case 2: {
            S.swap_by_ref();
            cout<<"New values are: ";
            S.display();
        }
    }
    return 0;
}
