// //Write a Program in C++ to implement stack using array
// #include <iostream>
// using namespace std;

// class node{
//     public:
//     int data;
//     node* next;
//     node (int d){
//         next = NULL;
//         data = d;
//   }
// };

// node* createStack(){
//     node *start = NULL;
//     return start;
// }

// node* pushInStack(int val, node *start){
//     node* cur = new node(val);
//     cur->next = start;
//     start = cur;
//     return start;
// }

// node* popFromStack(node *start){
//     node *temp = start;
//     start = start->next;
//     delete temp;
//     return start;
// }
// int topElement(node *start){
//     if(start==NULL){
//         cout<<"Stack is empty!"<<endl;
//         return -1;
//     }
//     return start->data;
// }
// int main()
// {   cout<<"Enter the no of elements in stack: ";
//     int n;
//     cin>>n;
//     node *start = createStack();
//     cout<<"\nEnter the elements: ";
//     while(n--){
//         int no;
//         cin>>no;
//         start = pushInStack(no, start);
//     }
//     cout<<"\nIMPLEMENTING STACK USING LINKED LIST\n";
//     cout<<"Top of stack: "<<topElement(start)<<endl;
//     cout<<"Popping top element!"<<endl;
//     start = popFromStack(start);
    
//     cout<<"Top after element after popping once is: "<<topElement(start);
    
//     return 0;
// }
