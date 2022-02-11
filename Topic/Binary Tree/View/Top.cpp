vector <int> bottomView(Node *root){
    vector<int> ans;
    if(!root) return ans;
    
    map<int,int> mp;
    queue<pair<Node*,int>> q;
    q.push({root,0});
    
    while(!q.empty()){
        Node* curr=q.front().first;
        int col=q.front().second;
        q.pop();
        
        if(mp.find(col)==mp.end()) mp[col]=curr->data;
        if(curr->left) q.push({curr->left,col-1});
        if(curr->right) q.push({curr->right,col+1});
    }
    
    map<int,int>:: iterator it=mp.begin();
    while(it!=mp.end()){
        ans.push_back((*it).second);
        it++;
    }
    return ans;
}