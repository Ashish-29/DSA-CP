void traverse(TreeNode* root,vector<int> & ans){
    if(!root) return;
    ans.push_back(root->val);
    traverse(root->left,ans);
    traverse(root->right,ans);
}
 
vector<int> inorderTraversal(TreeNode* root) {
    vector<int> ans;
    traverse(root,ans);
    return ans;
}