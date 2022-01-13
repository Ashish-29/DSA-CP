#include<bits/stdc++.h>
using namespace std;

double ffunction(double x){
    return x*x*x-3*x-5;
}

int main(){
    double delta=1e-6;
    double a,b;

    cout<<"Please enter endpoints A ans B of the interval [A,B] :"<<endl;
    cin>>a>>b;

    cout<<endl<<"The interval range from "<<a<<" to "<<b<<"."<<endl;

    double ya=ffunction(a);
    double yb=ffunction(b);
    int maxn=1+(log(b-a)-log(delta))/log(2);
    cout<<"MAX="<<maxn<<endl<<endl;

    if(ya*yb>=0){
        cout<<"The values ffunction(A) and ffunction(B) do not differ in sign."<<endl<<endl;
        return 0;
    }

    int k;
    double c,yc;
    for(k=1;k<=maxn;k++){
        c=(a+b)/2;
        yc=ffunction(c);

        if(yc==0){
            a=c;
            b=c;
        }
        else if((yb>=0 && yc>=0)||(yb<0 && yc<0)){
            b=c;
            yb=yc;
        }
        else {
            a=c;
            ya=yc;
        }

        if((b-a)<delta) break;
    }

    cout<<"The maximum number of iteration is "<<maxn<<"."<<endl;
    cout<<"The number of performed iteration is "<<k<<"."<<endl;
    cout<<"The computed root of f(x)=0 is "<<c<<"."<<endl;
    cout<<"The accuracy is +- "<<b-a<<"."<<endl;
    cout<<"The value of the function f(c) is "<<yc<<"."<<endl<<endl;

    return 0;
}