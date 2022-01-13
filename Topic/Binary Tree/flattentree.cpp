#include<bits\stdc++.h>
using namespace std;

class Node {
  public:
   int data;
   Node *left,*right;
   Node (int da) {data=da;left=right=NULL;}
};

void flatten(Node* root){
    if(!root || (!root->left && !root->right)) return ;

    if(root->left){
        flatten(root->left);

        Node* temp=root->right;
        root->right=root->left;
        root->left=NULL;

        Node* t=root;
        while(t->right) t=t->right;

        t->right=temp;
        
    }
    flatten(root->right);
}

void inorder(Node* root){
    if(!root) return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}


int main(){
    Node *root= new Node(1);
    root->left= new Node(2);
    root->right= new Node(3);
    root->left->left= new Node(4);
    root->left->right= new Node(5);
    root->right->left= new Node(6);
    root->right->right= new Node(7);
    root->right->left->left= new Node(8);

    inorder(root);cout<<endl;
    flatten(root);
    inorder(root);cout<<endl;

    return 0;
}