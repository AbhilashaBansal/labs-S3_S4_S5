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

void inorder(node *root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

int largestInBst(node* root){
    if(root==NULL){
        cout<<"BST is empty.\n";
        return -1;
    }
    node* temp = root;
    while(temp->right!=NULL){
        temp = temp->right;
    }
    int ans = temp->data;
    cout<<"The largest element in BST is: "<<ans<<endl;
    return ans;
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
    cout<<"\nFinding the largest element in the BST now...\n";
    int ans = largestInBst(root);
}
