#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(s) int(s.size())

// Radix Sort Algorithm
// Time Complexity: O(n * k)
// Space Complexity: O(n + k)

/* Radix sort is a non-comparative integer sorting algorithm that sorts data with integer keys by grouping keys by the individual digits which share the same significant position and value. A positional notation is required, but because integers can represent strings of characters (e.g., names or dates) and specially formatted floating point numbers, radix sort is not limited to integers.
 */

void radixSort(int arr[], int n){
    int max = *max_element(arr, arr + n);
    for(int exp = 1; max / exp > 0; exp *= 10){
        int output[n];
        int i, count[10] = {0};
        for(i = 0; i < n; i++){
            count[(arr[i] / exp) % 10]++;
        }
        for(i = 1; i < 10; i++){
            count[i] += count[i - 1];
        }
        for(i = n - 1; i >= 0; i--){
            output[count[(arr[i] / exp) % 10] - 1] = arr[i];
            count[(arr[i] / exp) % 10]--;
        }
        for(i = 0; i < n; i++){
            arr[i] = output[i];
        }
    }
}

int main(){
    int arr[] = {170, 45, 75, 90, 802, 24, 2, 66};
    int n =  sizeof(arr) / sizeof(arr[0]);
    radixSort(arr, n);
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    return 0;
}