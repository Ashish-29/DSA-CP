#include<bits\stdc++.h>
using namespace std;

#define vi vector<int>
#define pb push_back

class Node {
  public:
   int data;
   Node *left,*right;
   Node (int da) {data=da;left=right=NULL;}
};

void inorder(Node* root){
    if(!root) return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

Node* BalancedBST(vi arr,int st,int en){
    if(st>en) return NULL;
    else if(st==en) return new Node(arr[st]);
    
    int mid=(st+en)/2;
    Node* root=new Node(arr[mid]);

    root->left=BalancedBST(arr,st,mid-1);
    root->right=BalancedBST(arr,mid+1,en);

    return root;
}

int main(){
    vi arr={12,23,34,45,56,67,78,89,99};

    Node* root=BalancedBST(arr,0,8);
    inorder(root);

    return 0;
}