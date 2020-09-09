// Main function of the C++ program.

#include <iostream>
using namespace std;

class node{
    public:
    int coef, power;
    node *next;
    node(int cof, int pw){
        coef = cof;
        power = pw;
        next = NULL;
    }
};

node *addNode(int cof, int pw, node *poly)
{
    if(poly==NULL){
        node *root = new node(cof, pw);
        return root;
    }
    node *temp = poly;
    while(temp->next!=NULL){
        temp = temp->next;
    }
    temp->next = new node(cof, pw);
    return poly;
}

node *addMultipliedNode(int cof, int pw, node* poly3){
    if(poly3==NULL){
        node *root = new node(cof, pw);
        return poly3 = root;
    }
    if(pw>poly3->power){
        node *root = new node(cof, pw);
        root->next = poly3;
        poly3 = root;
        return poly3;
    }
    
    if(pw==poly3->power){
        poly3->coef += cof;
        return poly3;
    }
    
    node *temp = poly3;
    while(temp->next!=NULL && temp->next->power>=pw){
        temp = temp->next;        
    }
    if(temp->power==pw){
        temp->coef += cof;
        return poly3;
    }
    if(temp->power>pw){
        node *root = new node(cof, pw);
        root->next = temp->next;
        temp->next = root;
        return poly3;
    }
}

void printLL(node *);

node* multiply(node* poly1, node* poly2, node* poly) 
{   
    if(poly1==NULL || poly2==NULL){
        cout<<"Cannot multiply empty linked list!";
        return poly=NULL;
    }
    node *ptr1 = poly1;
    node *ptr2 = poly2;
    node *poly3 = poly;
    while (ptr1 != NULL) { 
        while (ptr2 != NULL) {
            //loop to iterate over all nodes (terms) of polynomial 2
            int coeff, power; 
            //cout<<"Here"<<endl;
            coeff = ptr1->coef*ptr2->coef; 
            power = ptr1->power + ptr2->power; 
  
            poly3 = addMultipliedNode(coeff, power, poly3); 
            ptr2 = ptr2->next;
            //printLL(poly3);
        } 
        //resetting the pointer to beginning of second polynomial
        ptr2 = poly2; 
        ptr1 = ptr1->next; 
    } 
  
    return poly3; 
} 

void printLL(node *root){
    node* temp = root;
    while(temp->next!=NULL){
        cout<<temp->coef<<" x^"<<temp->power<<" + ";
        temp = temp->next;
    }
    cout<<temp->coef<<" x^"<<temp->power<<endl;
}
int main()
{
    node *polynomial_1 = NULL;
    node *polynomial_2 = NULL;
    cout<<"Enter the total no of terms in polynomial 1: ";
    int n1;
    cin>>n1;
    cout<<"Note: Please enter all terms in decreasing order of power!\n\n";
    for(int i=1; i<=n1; i++){
        cout<<"Enter term "<<i<<" (coefficient followed by power) : ";
        int pw, cof;
        cin>>cof>>pw;
        polynomial_1 = addNode(cof, pw, polynomial_1);
    }
    cout<<"Enter the total no of terms in polynomial 2: ";
    int n2;
    cin>>n2;
    
    cout<<"Note: Please enter all terms in decreasing order of power!\n\n";
    for(int i=1; i<=n2; i++){
        cout<<"Enter term "<<i<<" (coefficient followed by power) : ";
        int pw, cof;
        cin>>cof>>pw;
        polynomial_2 = addNode(cof, pw, polynomial_2);
    }
    
    cout<<"Polynomial 1 : ";
    printLL(polynomial_1);
    cout<<"Polynomial 2 : ";
    printLL(polynomial_2);
    node *resultPoly = NULL;
    cout<<"\n-------------RESULT AFTER POLYNOMIAL MULTIPLICATION------------\n";
    resultPoly = multiply(polynomial_1, polynomial_2, resultPoly);
    //printing the result
    printLL(resultPoly);
    return 0;
}
