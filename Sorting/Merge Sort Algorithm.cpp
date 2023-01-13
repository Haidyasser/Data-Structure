#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(s) int(s.size())

// Merge Sort Algorithm
// Time Complexity: O(nlogn)
// Space Complexity: O(n)

/* Merge Sort is a Divide and Conquer algorithm. It divides input array in two halves, calls itself for the two halves and then merges the two sorted halves.
The merge() function is used for merging two halves. The merge(arr, l, m, r) is key process that assumes that arr[l..m] and arr[m+1..r] are sorted and merges the two sorted sub-arrays into one.
*/

void merge(int arr[], int l, int m, int r){
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1], R[n2];
    for(int i = 0; i < n1; i++) 
        L[i] = arr[l + i];
    for(int i = 0; i < n2; i++) 
        R[i] = arr[m + 1 + i];
    int i = 0, j = 0, k = l;
    while(i < n1 && j < n2){
        if(L[i] <= R[j]) 
            arr[k++] = L[i++];
        else 
            arr[k++] = R[j++];
    }
    while(i < n1) 
        arr[k++] = L[i++];
    while(j < n2) 
        arr[k++] = R[j++];
}

void mergeSort(int arr[], int l, int r){
    if(l < r){
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++) 
        cin >> arr[i];
    mergeSort(arr, 0, n - 1);
    for(int i = 0; i < n; i++) 
        cout << arr[i] << " ";
    return 0;
}