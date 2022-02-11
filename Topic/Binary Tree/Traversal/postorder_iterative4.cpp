vector<int> postorderTraversal(TreeNode* root) {
    vector<int> ans;
    if(!root) return ans;
    stack<TreeNode*> st;
    
    while(root || st.size()){
        if(root){
            st.push(root);
            root=root->left;
        }
        else {
            TreeNode* curr=st.top()->right;
            
            if(curr) root=curr;
            else {                    
                while (!st.empty() && st.top()->right==curr) {
                    curr=st.top();
                    ans.push_back(curr->val);
                    st.pop();
                }                
            }
        }
    }
          
    return ans;
}