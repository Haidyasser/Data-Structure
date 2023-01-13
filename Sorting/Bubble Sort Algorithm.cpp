#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(s) int(s.size())

// Bubble Sort Algorithm
// Time Complexity: O(n^2)
// Space Complexity: O(1)

/*
Bubble Sort is the simplest sorting algorithm that works by repeatedly swapping the adjacent elements if they are in the wrong order.
This algorithm is not suitable for large data sets as its average and worst-case time complexity is quite high.
 */

void bubbleSort(int arr[], int n){
    for(int i = 0; i < n; i++){
        // Last i elements are already in place
        for(int j = 0; j < n - i - 1; j++){
            if(arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
        }
    }
}

int main()
{
    int arr[] = {5, 6, 3, 2, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    bubbleSort(arr, n);
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    return 0;
}