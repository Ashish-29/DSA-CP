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

void preorder(Node* root){
    if(!root) return;
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

vector<Node*> PossibleBST(int st,int en){
    vector<Node*> tree;   
    if(st>en) {tree.pb(NULL);return tree;}
    for(int i=st;i<=en;i++){
        vector<Node*> leftree=PossibleBST(st,i-1);
        vector<Node*> rightree=PossibleBST(i+1,en);

        for(int j=0;j<leftree.size();j++){
            for(int k=0;k<rightree.size();k++){
                Node* root=new Node(i);
                root->left=leftree[j];
                root->right=rightree[k];
                tree.pb(root);
            }
        }
    }
    return tree;
}

int main(){
    cout<<"start"<<endl;
    vector<Node*> root=PossibleBST(1,3);
    for(int i=0;i<root.size();i++) {
        cout<<i+1<<" : ";
        preorder(root[i]);
        cout<<endl;
    }
    cout<<"end";
    return 0;
}