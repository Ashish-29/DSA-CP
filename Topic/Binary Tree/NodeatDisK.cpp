#include<bits\stdc++.h>
using namespace std;

#define vi vector<int>
#define pb push_back

vi ans;

class Node {
  public:
   int data;
   Node *left,*right;
   Node (int da) {data=da;left=right=NULL;}
};

void find(Node* root,int k){
    if(!root || k<0) return;
    if(k==0){ans.push_back(root->data);return;}
    if(root->left) find(root->left,k-1);
    if(root->right) find(root->right,k-1);
}

int findtarget(Node* root,int n,int k ){
    if(!root) return -1;
    if(root->data==n){find(root,k);return 1;}
    
    int d1=findtarget(root->left,n,k);
    if(k==d1) {ans.pb(root->data);return -1;}
    else if(d1!=-1) {find(root->right,k-d1-1);return d1+1;}

    int d2=findtarget(root->right,n,k);
    if(k==d2) {ans.pb(root->data);return -1;}
    else if(d2!=-1) {find(root->left,k-d2-1);return d2+1;}

    return -1;
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

    int n,k;
    cin>>n>>k;
    int res=findtarget(root,n,k);
    cout<<endl;
    if(!ans.size()) cout<<"NO element"<<endl;
    for(int i=0;i<ans.size();i++) cout<<ans[i]<<" ";

    return 0;
}