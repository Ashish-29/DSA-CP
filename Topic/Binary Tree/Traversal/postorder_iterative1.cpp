vector<int> postorderTraversal(TreeNode* root) {
    vector<int> ans;
    if(!root) return ans;
    stack<TreeNode*> st;
    
    while(root || st.size()){
        if(root){
            st.push(root);
            ans.push_back(root->val);
            root=root->right;
        }
        else{                
            root=st.top()->left;
            st.pop();
        }
    } 
    reverse(ans.begin(),ans.end());       
    return ans;
}