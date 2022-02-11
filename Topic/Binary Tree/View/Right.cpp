vector<int> rightView(Node *root){  
   vector<int> ans;
   if(!root) return ans;
   queue<Node* > q;
   q.push(root);
   
    while(!q.empty()){
        int n=q.size();
        
        while(n--){
            Node* curr=q.front();
            q.pop();
            if(!n) ans.push_back(curr->data);
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
    dfs(root->right, level+1, ans);
    dfs(root->left, level+1, ans);
}

vector<int> leftSideView(TreeNode *root) {
    vector<int> ans;
    dfs(root, 0, ans);
    return ans;
}