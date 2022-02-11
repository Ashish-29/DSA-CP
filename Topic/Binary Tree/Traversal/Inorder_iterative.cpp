vector<int> inorderTraversal(TreeNode* root) {
    vector<int> ans;
    if(!root) return ans;
    stack<TreeNode*> st;
    
    while(root || st.size()){
        if(root){
            st.push(root);
            root=root->left;
        }
        else{
            ans.push_back(st.top()->val);
            root=st.top()->right;
            st.pop();
        }
    }
            
    return ans;
}