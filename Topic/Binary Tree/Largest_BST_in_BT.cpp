#include<bits\stdc++.h>
using namespace std;

class Node {
  public:
   int data;
   Node *left,*right;
   Node (int da) {data=da;left=right=NULL;}
};

class Info {
public:
    int ans;
    int MIN;
    int MAX;
    int size;
    bool isBST;
};

Info LgstBSTinBT (Node* root){
    if(!root) return {0,INT_MAX,INT_MIN,0,1};
    if(root->left==NULL && root->right==NULL) return {1,root->data,root->data,1,1};

    Info left=LgstBSTinBT (root->left);
    Info right=LgstBSTinBT (root->right);

    Info curr;
    if(left.isBST && right.isBST && left.MAX<root->data && right.MIN>root->data){
        curr.isBST=1;
        curr.MIN=min(left.MIN,root->data);
        curr.MAX=max(right.MAX,root->data);
        curr.size=1+left.size+right.size;
        curr.ans=curr.size;
    }
    else{
        curr.isBST=0;
        curr.ans=max(left.ans,right.ans);
    }
    return curr;
}

int main(){
    Node *root= new Node(15);
    root->left= new Node(20);
    root->right= new Node(30);
    root->left->left= new Node(5);

    cout<<LgstBSTinBT(root).ans<<endl;

    return 0;
}