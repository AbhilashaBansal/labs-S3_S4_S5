//Write a Program in C++ to implement stack using linkedlist

#include <iostream>
using namespace std;

class Stack{
    public:
    int *a;
    int top_index;
    int max_size;
    int cur_size;
    Stack(int ms = 50){
        a = new int[ms];
        top_index=-1;
        cur_size = 0;
        max_size = ms;
    }
    int top(){
        if(top_index==-1){
            cout<<"Stack is empty!\n";
            return -1;
        }
        return a[top_index];
    }
    void push(int val){
        if(cur_size==max_size){
            cout<<"Stack is full, overflow!"<<endl;
        }
        else{
            a[++top_index] = val;
            cur_size++;
        }
    }
    int pop(){
        if(top_index==-1){
            cout<<"Underflow! Stack is empty.\n";
            return -1;
        }
        top_index--;
        cur_size--;
        return a[top_index+1];
    }
};

int main()
{
    Stack s(20);
    int n;
    cout<<"Enter the no of elements in stack: ";
    cin>>n;
    cout<<"Enter the elements to be inserted in stack: ";
    while(n--){
        int no;
        cin>>no;
        s.push(no);
    }
    cout<<"\nIMPLEMENTING STACK USING ARRAY\n";
    cout<<"Top element of stack is: "<<s.top();
    cout<<"\nPopping top element from stack!\n";
    int elt = s.pop();
    cout<<elt<<" has been popped.\n";
    cout<<"New top element is: "<<s.top()<<endl;
    return 0;
}
