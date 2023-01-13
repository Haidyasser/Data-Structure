#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(s) int(s.size())

// Quick Sort Algorithm
// Time Complexity: O(nlogn)
// Space Complexity: O(n)

/* QuickSort is a Divide and Conquer algorithm. It picks an element as pivot and partitions the given array around the picked pivot. There are many different versions of quickSort that pick pivot in different ways.
Always pick first element as pivot.
Always pick last element as pivot (implemented below)
Pick a random element as pivot.
Pick median as pivot.
The key process in quickSort is partition(). Target of partitions is, given an array and an element x of array as pivot, put x at its correct position in sorted array and put all smaller elements (smaller than x) before x, and put all greater elements (greater than x) after x. All this should be done in linear time.
*/

int partition(int arr[], int l, int r){
    int pivot = arr[r];
    int i = l - 1;
    for(int j = l; j < r; j++){
        if(arr[j] < pivot)
            swap(arr[++i], arr[j]);
    }
    swap(arr[++i], arr[r]);
    return i;
}

void quickSort(int arr[], int l, int r){
    if(l < r){
        int p = partition(arr, l, r);
        quickSort(arr, l, p - 1);
        quickSort(arr, p + 1, r);
    }
}

int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++) 
        cin >> arr[i];
    quickSort(arr, 0, n - 1);
    for(int i = 0; i < n; i++) 
        cout << arr[i] << " ";
    return 0;
}