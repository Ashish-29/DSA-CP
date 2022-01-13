#include<bits/stdc++.h>
using namespace std;

string reverse(string s){
    string f;
    for (int i=s.size()-1;i>=0;i--) f+=s[i];
    return f;
}

int prc(char c){
    if (c=='^') return 3;
    else if (c=='*' || c=='/') return 2;
    else if (c=='+' || c=='-') return 1;
    else return -1;
}

string Infix_to_prefix (string s1){
    
    string s=reverse(s1);
    string ans;
    stack<char>st;

    for(int i=0;i<s.size();i++) {
        char c=s[i];

        if((c>='a'&& c<='z')||(c>='A' && c<='Z')) ans+=c;
        else if (st.empty() || c==')' || c=='}' || c==']') st.push(c);

        else if (c=='(') { while(st.top()!=')'){ans+=st.top();st.pop();}st.pop();}
        else if (c=='{') { while(st.top()!='}'){ans+=st.top();st.pop();}st.pop();}
        else if (c=='[') { while(st.top()!=']'){ans+=st.top();st.pop();}st.pop();}

        else if (prc(c)>prc(st.top())) st.push(c);

        else if (prc(c)==prc(st.top())){
            if(prc(c)==3) ans+=c;
            else st.push(c);
        }

        else {
            while(!(st.empty() || st.top()==')' || st.top()=='}' || st.top()==']') && prc(c)<prc(st.top()))
            {ans+=st.top();st.pop();}
            st.push(c);
        }
    }

    while(!st.empty()){ans+=st.top();st.pop();}
    return reverse(ans);
}

int main(){
    string s;
    cin>>s;
    string postfix=Infix_to_prefix(s);
    cout<<postfix;

    return 0;
}