// Write a Program in C++ to create and traverse linked list.

#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node(int d){
        data = d;
    }
};

//INSERTION FUNCTION 
Node* insert(int n){
    int no;
    cin>>no;
    Node *root = new Node(no);
    Node* temp = root;
    for(int i=1; i<n; i++){
        cin>>no;
        temp->next = new Node(no);
        temp = temp->next;
    }
    return root;
}

int main()
{
    int n;
    cout<<"Enter the number of elements you want to insert in Linked List: "<<endl;
    cin>>n;
    cout<<"Enter the elements: "<<endl;
    
    //creating the Linked List
    Node* root = insert(n);
    
    //Traversing the Linked List
    cout<<"The elements in Linked List are: "<<endl;
    Node* temp = root;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
    
    //deleting the nodes of LL
    //DELETION
    Node* del = root;
    while(del!=NULL){
        Node* prev = del;
        del = del->next;
        cout<<"Deleting node with value: "<<prev->data<<endl;
        delete prev;
    }
    return 0;
}
