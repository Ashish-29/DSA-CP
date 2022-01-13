#include<bits/stdc++.h>
using namespace std;

int prc(char c){
    if (c=='^') return 3;
    else if (c=='*' || c=='/') return 2;
    else if (c=='+' || c=='-') return 1;
    else return -1;
}

string Infix_to_postfix (string s){
    string ans;
    stack<char>st;
    for(int i=0;i<s.size();i++) {
        char c=s[i];

        if((c>='a'&& c<='z')||(c>='A' && c<='Z')) ans+=c;
        else if (st.empty() || c=='(') st.push(c);
        else if (c==')') {
            while(st.top()!='('){
                ans+=st.top();
                st.pop();
            }
            st.pop();
        }
        else if (prc(c)>prc(st.top())) st.push(c);
        else if (prc(c)==prc(st.top())){
            if(prc(c)==3) st.push(c);
            else {
                ans+=st.top();
                st.pop();
                st.push(c);
            }
        }
        else {
            while(!st.empty() && st.top()!='(' && prc(c)<=prc(st.top())){
                ans+=st.top();
                st.pop();
            }
            st.push(c);
        }
    }

    while(!st.empty()){
        ans+=st.top();
        st.pop();
    }
    return ans;
}

int main(){
    string s="a+b*(c^d-e)^(f+g*h)-i";
    string postfix=Infix_to_postfix(s);
    cout<<"\""<<postfix<<"\"";
    return 0;
}