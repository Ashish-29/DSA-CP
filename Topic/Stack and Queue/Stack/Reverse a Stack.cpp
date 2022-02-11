#include <bits/stdc++.h>
using namespace std;

void insert_at_bottom(stack<int> &s,int a){
    if(s.empty()) {s.push(a);return;}
        
    int curr=s.top();
    s.pop();
    insert_at_bottom(s,a);
    s.push(curr);
}

void reverse_stack(stack<int> &s){
    if(s.empty()) return;
        
    int curr=s.top();
    s.pop();
    reverse_stack(s);
    insert_at_bottom(s,curr);
}

void print_stack(stack<int> s){
    if(!s.empty()){
        cout<<s.top()<<" ";s.pop();
        print_stack(s);
    }
    else cout<<endl;
}

int main(){
    stack<int> s;
    
    vector<int> arr={1,2,3,4,5,6,7,8,9};
    for(auto i:arr) s.push(i);

    print_stack(s);
    reverse_stack(s);
    print_stack(s);

    return 0;
}