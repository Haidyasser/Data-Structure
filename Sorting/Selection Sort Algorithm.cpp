#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(s) int(s.size())

// Selection Sort Algorithm
// Time Complexity: O(n^2)
// Space Complexity: O(1)

/* Selection Sort Algorithm is a simple sorting algorithm. This sorting algorithm is an in-place comparison-based algorithm in which the list is divided into two parts, the sorted part at the left end and the unsorted part at the right end. Initially, the sorted part is empty and the unsorted part is the entire list.
The smallest element is selected from the unsorted array and swapped with the leftmost element, and that element becomes a part of the sorted array. This process continues moving unsorted array boundary by one element to the right.*/
// Selection Sort Algorithm is not suitable for large data sets as its average and worst case complexities are of Ο(n2), where n is the number of items.

void selectionSort(int arr[], int n)
{
    for(int i = 0; i < n; i++){
        int minIndex = i;
        for(int j = i + 1; j < n; j++){
            if(arr[j] < arr[minIndex]){
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);
    }
}

int main()
{
    int arr[] = {5, 6, 3, 2, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    selectionSort(arr, n);
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    return 0;
}