// Main function of the C++ program.

#include <iostream>
using namespace std;

class node{
    public:
    int data;
    node* left;
    node* right;
    node(int d){
        data = d;
        left = right = NULL;
    }
};

node* insertInBst(node* root, int x){
    if(root==NULL){
        return root = new node(x);
    }
    if(x<=root->data){
        root->left = insertInBst(root->left, x);
    }
    else if(x>root->data){
        root->right = insertInBst(root->right, x);
    }
    return root;
}

bool searchInBst(node* root, int x){
    if(root==NULL){
        return false;
    }
    if(root->data==x){
        cout<<x<<" is present in BST.\n";
        return true;
    }
    else if(root->data>x){
        return searchInBst(root->left,x);
    }
    else{
        return searchInBst(root->right,x);
    }
    return false;
}

node* deleteInBst(node* root, int x){
    if(root==NULL){
        return NULL;
    }
    if(x<root->data){
        root->left = deleteInBst(root->left, x);
        return root;
    }
    else if(x>root->data){
        root->right = deleteInBst(root->right, x);
        return root;
    }
    else{
        //this node has to be deleted
        if(root->left==NULL && root->right==NULL){
            delete root;
            cout<<"Successfully deleted element "<<endl;
            return NULL;
        }
        else if(root->left==NULL){
            node* temp = root->right;
            delete root;
            cout<<"Successfully deleted element "<<endl;
            return temp;
        }
        else if(root->right==NULL){
            node* temp = root->left;
            delete root;
            cout<<"Successfully deleted element "<<endl;
            return temp;
        }
        else{
            //both not null
            node *temp = root->right;
            //finding inorder successor
            while(temp->left!=NULL){
                temp=temp->left;
            }
            root->data = temp->data;
            root->right = deleteInBst(root->right, temp->data);
            return root;
        }
    }
    return root;
}

void inorder(node *root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

int main()
{
    node *root = NULL;
    int n;
    cout<<"Enter no of elements you want to insert in BST: ";
    cin>>n;
    cout<<"Enter the elements (space separated): ";
    while(n--){
        int x;
        cin>>x;
        root = insertInBst(root, x);
    }
    cout<<"\nBST created successfully!\n";
    int c=1;
    while(c!=4){
        cout<<"Press 1 to search in BST, 2 to delete an element from BST, 3 to print inorder traversal of BST, & 4 to exit.\n";
        cin>>c;
        switch(c){
            case 1: {
                int y;
                cout<<"Enter element to be searched for: ";
                cin>>y;
                bool p = searchInBst(root, y);
                if(!p){
                    cout<<"Element not found!\n";
                }
                break;
            }
            case 2: {
                int y;
                cout<<"Enter element to be deleted: ";
                cin>>y;
                root = deleteInBst(root, y);
                break;
            }
            case 3: {
                inorder(root);
                break;
            }
            case 4: {
                cout<<"Exiting...\n";
                break;
            }
            default: cout<<"Invalid choice!\n";
        }
    }
    
    cout<<"End of program.\n";
    return 0;
}
