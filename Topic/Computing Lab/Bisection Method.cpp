#include<bits/stdc++.h>
using namespace std;

double ffunction(double x) {return x*x*x-3*x-5;}

int main(){
    double delta=1e-6;
    double a,b;

up:
    cout << "Enter first guess: "; cin >> a;
    cout << "Enter second guess: "; cin >> b;

    double ya=ffunction(a);
    double yb=ffunction(b);

    if(ya==0) {cout<<"The root of f(x)=0 is "<<a<<"."<<endl;return 0;}
    if(yb==0) {cout<<"The root of f(x)=0 is "<<b<<"."<<endl;return 0;}

    if(ya*yb>0){
        cout << "Incorrect Initial Guesses." << endl;
        goto up;
    }

    double c,yc;
    int k=1,max_iteration=1+(log(b-a)-log(delta))/log(2);
    
    for(;k<=max_iteration;k++){
        c=double(a+b)/2;
        yc=ffunction(c);

        if(yc==0){
            a=c;
            b=c;
        }
        else if(yb*yc>0){
            b=c;
            yb=yc;
        }
        else {
            a=c;
            ya=yc;
        }

        if((b-a)<delta) break;
    }

    cout<<fixed<<setprecision(10);
    cout<<"\nThe maximum number of iteration is "<<max_iteration<<"."<<endl;
    cout<<"The number of performed iteration is "<<k<<"."<<endl;
    cout<<"The computed root of f(x)=0 is "<<c<<"."<<endl;
    cout<<"The accuracy is +-"<<b-a<<"."<<endl;
    cout<<"The value of the function f(c) is "<<yc<<"."<<endl<<endl;

    return 0;
}