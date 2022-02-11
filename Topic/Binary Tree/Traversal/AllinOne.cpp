#include<stack>
vector<vector<int>> getTreeTraversal(BinaryTreeNode<int> *root){
    vector<vector<int>> ans(3);
    if(!root) return ans;
    stack<pair<BinaryTreeNode<int>*,int>> s;
    s.push({root,1});
    
    while(s.size()){
        auto curr=s.top();
        s.pop();
        
        if(curr.second==1){                           //Inorder
            ans[1].push_back(curr.first->data);
            curr.second++;
            s.push(curr);            
            if(curr.first->left) s.push({curr.first->left,1});
        }
        else if(curr.second==2){                     //Preorder
            ans[0].push_back(curr.first->data);
            curr.second++;
            s.push(curr);          
            if(curr.first->right) s.push({curr.first->right,1});
        }
        else ans[2].push_back(curr.first->data);        //Postorder    
    }
  	return ans;
}