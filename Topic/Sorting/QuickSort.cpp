//Best case    O(N*log(N))
//Average case O(N*log(N))
//Worst case   O(N^2)

#include <bits/stdc++.h>
using namespace std;

void quicksort (vector<int> &arr,int st,int en){
    if (en-st<1) return;
    
    int j=st;     
    for (int i=st;i<en;i++){
        if (arr[i]<arr[en]) {        //pivot=arr[en];
            swap(arr[i],arr[j]);
            j++;
        }
    }
    swap(arr[j],arr[en]);
    
    quicksort(arr,st,j-1);    
    quicksort(arr,j+1,en);   
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for (int i=0;i<n;i++) cin>>arr[i];
    quicksort(arr,0,n-1);  
    for (int i=0;i<n;i++) cout<<arr[i]<<" ";
    return 0;
}