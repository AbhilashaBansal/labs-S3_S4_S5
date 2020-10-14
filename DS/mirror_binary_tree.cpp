#include <iostream>
#include <queue>
using namespace std;

class node{
    public:
    int data;
    node* left;
    node* right;
    node(int d){
        data=d;
        left=right=NULL;
    }
};

void mirror_1(node* root){
    if(root==NULL){
        return;
    }
    mirror_1(root->left);
    mirror_1(root->right);
    node* temp = root->right;
    root->right = root->left;
    root->left = temp;
    //delete temp;
    return;
}

node* mirror(node* root){
    if(root==NULL){
        return NULL;
    }
    node* m_root = new node(root->data);
    m_root->left = mirror(root->right);
    m_root->right = mirror(root->left);
    
    return m_root;
}

void level_order(node* root){
    queue<node*>q;
    if(root==NULL){
        return;
    }
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        node* front = q.front();
        //q.pop();
        if(front==NULL){
            cout<<endl;
            q.pop();
            if(!q.empty())
                q.push(NULL);
            continue;
        }
        cout<<front->data<<" ";
        q.pop();
        if(front->left){
            q.push(front->left);
        }
        if(front->right){
            q.push(front->right);
        }
    }
}

int main() {
    //creating Binary Tree
    node* root = new node(5);
    root->left = new node(3);
    root->left->left = new node(2);
    root->left->right = new node(4);
    root->right = new node(7);
    root->right->left = new node(6);
    root->right->right = new node(8);
    level_order(root);
    //creating mirror image
    node* m_root=mirror(root);
    cout<<"\nPrinting level order traversal of mirror image of tree..\n";
    level_order(m_root);
    return 0;
}
