class node{
        node* a[26];
        bool endofWord;
    public:
        node(){
            this->endofWord=false;
            for(int i=0;i<26;i++) this->a[i]=NULL;
        }
    
        void insert(int idx){
            this->a[idx]=new node();
        }
    
        bool containskey(int idx){
            if(this->a[idx]) return true;
            return false;
        }
    
        node* next(int idx){
            return this->a[idx];
        }
    
        bool isend(){
            return this->endofWord;
        }
    
        void makend(){
            this->endofWord=true;
        }
};


class Trie {
    node* root;
public:
    Trie() {
        root=new node();
    }
    
    void insert(string word) {
        node* temp=root;
        
        for(int i=0;i<word.size();i++){
            int idx=word[i]-'a';
            
            if(!temp->containskey(idx)) temp->insert(idx);
            temp=temp->next(idx);
        }
        temp->makend();
    }
    
    bool search(string word) {
        node* temp=root;
        
        for(int i=0;i<word.size();i++){
            int idx=word[i]-'a';
            
            if(!temp->containskey(idx)) return false;
            temp=temp->next(idx);
        }
        return temp->isend();
    }
    
    bool startsWith(string prefix) {
        node* temp=root;
        
        for(int i=0;i<prefix.size();i++){
            int idx=prefix[i]-'a';
            
            if(!temp->containskey(idx)) return false;
            temp=temp->next(idx);
        }
        return true;
    }
};

/**
 * Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */