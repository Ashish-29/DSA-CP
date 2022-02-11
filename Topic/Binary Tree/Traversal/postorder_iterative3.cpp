vector<int> postorderTraversal(TreeNode* root) {
    vector<int> ans;
    if(!root) return ans;
    stack<TreeNode*> s1,s2;
    
    while(root || s1.size()){
        if(root){
            s1.push(root);
            s2.push(root);
            if(root->right) s1.push(root->right);
            root=root->left;
        }
        else {
            while (s2.size() && s1.top()==s2.top()) {
                ans.push_back(s1.top()->val);
                s1.pop();
                s2.pop();
            }
            if(s1.size()) {
                root=s1.top();
                s1.pop();
            }
        }
    }
          
    return ans;
}