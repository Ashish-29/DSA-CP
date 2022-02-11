void traverse(TreeNode* root,vector<int> & ans){
    if(!root) return;
    traverse(root->left,ans);
    traverse(root->right,ans);
    ans.push_back(root->val);
}

vector<int> inorderTraversal(TreeNode* root) {
    vector<int> ans;
    traverse(root,ans);
    return ans;
}