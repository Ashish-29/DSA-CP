//Best case    O(N)
//Average case O(N^2)
//Worst case   O(N^2)

#include <bits/stdc++.h>
using namespace std;

void insertionsort (vector <int> &arr){
    int n=arr.size();

    for (int i=1;i<n;i++){
        int a=arr[i],j=i-1;
        while (j>=0 && arr[j]>a){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=a;
    }
}


int main() {
    int n;
    cin>>n;
    vector<int> arr(n);
    for (int i=0;i<n;i++) cin>>arr[i];
    
    insertionsort(arr);
    
    for (int i=0;i<n;i++) cout<<arr[i]<<" ";

    return 0;
}