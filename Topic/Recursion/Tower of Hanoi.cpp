#include<bits/stdc++.h>
using namespace std;

void TowerofHanoi(int n,char src,char helper,char des) {
    if(n==0) return;
    
    TowerofHanoi(n-1,src,des,helper);               //move n-1 hanoi from source to helper 
    cout<<"Move from "<<src<<" to "<<des<<endl;     //move 1 hanoi from src to des
    TowerofHanoi(n-1,helper,src,des);               //move n-1 hanoi from helper to des 
}


int main() {
    int n;
    cin>>n;
    
    TowerofHanoi(n,'A','B','C');
}