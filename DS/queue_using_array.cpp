// Main function of the C++ program.

//USING STATIC MEMORY ALLOCATION
#include <iostream>
using namespace std;

const int size = 100;
class Queue{
    public:
    int a[size];
    int front, rear, cs, ms;
    Queue(){
        front = rear = -1;
        cs=0;
        ms=size;
    }
    void push(int x){
        if(rear==ms-1){
            cout<<"Overflow!\n";
            return;
        }
        if(cs==0){
            front=rear=0;
            a[rear] = x;
            cs++;
        }
        else{
            rear++;
            a[rear] = x;
            cs++;
        }
        cout<<x<<" inserted successfully!\n";
    }
    
    int pop(){
        if(cs==0){
            cout<<"Underflow!\n";
            return -1;
        }
        else if(front==rear){
            cs=0;
            int p = a[front];
            front = rear = -1;
            cout<<p<<" deleted successfully!\n";
            return p;
        }
        else{
            int p = a[front];
            front++;
            cs--;
            cout<<p<<" deleted successfully!\n";
            return p;
        }
    }
    int front_fn(){
        if(cs==0){
            cout<<"Underflow!\n";
            return -1;
        }
        else{
            int p=a[front];
            return p;
        }
    }
    bool isEmpty(){
        if(cs==0){
            return true;
        }
        else{
            return false;
        }
    }
};

int main()
{
 Queue q;
 q.push(1);
 q.push(2);
 q.push(3);
 q.push(4);
 q.push(5);
 int p = q.pop();
 int f = q.front_fn();
 if(f!=-1){
     cout<<"Front element of queue is: "<<f<<endl;
 }
 bool x = q.isEmpty();
 if(x){
     cout<<"Queue is empty.\n";
 }
 else{
     cout<<"Queue is not empty.\n";
 }
}
