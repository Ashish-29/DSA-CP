#include<bits\stdc++.h>
using namespace std;

#define vi vector<int>
#define pb push_back

int maxsum=INT_MIN;

class Node {
  public:
   int data;
   Node *left,*right;
   Node (int da) {data=da;left=right=NULL;}
};

int findmaxsum(Node* root){
    if(!root) return 0;
    int s1=0,s2=0,s3=0,s4=0;

    s1=root->data;
    s2=findmaxsum(root->left);
    s3=findmaxsum(root->right);

    s4=max(s1,max(s1+s2,s1+s3));
    maxsum=max(maxsum,max(s4,s1+s2+s3));
    return s4;
}

int main(){
    Node *root= new Node(1);
    root->left= new Node(5);
    root->left->left= new Node(6);
    root->left->left->right= new Node(7);
    root->left->left->right->left= new Node(8);
    root->left->left->right->right= new Node(9);
    root->right= new Node(2);
    root->right->left= new Node(3);
    root->right->right= new Node(4);

    int ans=findmaxsum(root);
    cout<<maxsum<<endl;

    return 0;
}