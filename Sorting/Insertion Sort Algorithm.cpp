#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(s) int(s.size())

// Insertion Sort Algorithm
// Time Complexity: O(n^2)
// Space Complexity: O(1)

/* Insertion Sort is a simple sorting algorithm that works the way we sort playing cards in our hands. The array is virtually split into a sorted and an unsorted part. Values from the unsorted part are picked and placed at the correct position in the sorted part.
Insertion Sort Algorithm is not suitable for large data sets as its average and worst case complexities are of Ο(n2), where n is the number of items.
 */

void insertionSort(int arr[], int n){
    for(int i = 1; i < n; i++){
        int key = arr[i];
        int j = i - 1;
        while(j >= 0 && arr[j] > key){
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int main(){
    int arr[] = {5, 4, 3, 2, 1};
    int n =  sizeof(arr) / sizeof(arr[0]);
    insertionSort(arr, n);
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    return 0;
}
