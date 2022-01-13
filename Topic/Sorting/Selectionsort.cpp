//Best case    O(N^2)
//Average case O(N^2)
//Worst case   O(N^2)

#include <bits/stdc++.h>
using namespace std;

void Selectionsort(vector <int> &arr){
    int n = arr.size();
    for (int i = 0; i < n - 1; i++){
        for (int j = i + 1; j < n; j++){
            if (arr[i] > arr[j]){
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin>>arr[i];

    Selectionsort(arr);

    for (int i = 0; i < n; i++) cout<<arr[i]<<" ";

    return 0;
}