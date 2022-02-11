vector<int> leftView(Node *root){ 
   vector<int> ans;
   if(!root) return ans;
   queue<Node* > q;
   q.push(root);
   
   while(!q.empty()){
        int n=q.size();
        Node* curr=q.front();
        ans.push_back(curr->data);
        
        while(n--){
            curr=q.front();
            q.pop();
            if(curr->left) q.push(curr->left);
            if(curr->right) q.push(curr->right);
        }
   }
   
   return ans;
}
/************************************************************************************************/
 
void dfs(TreeNode *root, int level, vector<int> &ans){
    if(!root) return ;
    if(ans.size()==level) ans.push_back(root->val);
    dfs(root->left, level+1, ans);
    dfs(root->right, level+1, ans);
}

vector<int> leftSideView(TreeNode *root) {
    vector<int> ans;
    dfs(root, 0, ans);
    return ans;
}