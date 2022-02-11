vector<int> preorderTraversal(TreeNode* root) {
    vector<int> ans;
    if(!root) return ans;
    stack<TreeNode*> st;
    
    while(root || st.size()){
        if(root){
            st.push(root);
            ans.push_back(root->val);
            root=root->left;
        }
        else{                
            root=st.top()->right;
            st.pop();
        }
    }
            
    return ans;
}