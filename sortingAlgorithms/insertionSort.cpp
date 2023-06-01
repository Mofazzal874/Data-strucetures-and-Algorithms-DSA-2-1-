//Insertion sort implementation
//Time Complexity: O(n^2)
//Space Complexity: O(1)
//Stable: Yes
//Inplace: Yes
//Online: Yes
//Adaptive: Yes
//Uses: When the array is almost sorted
//      When the array is small

// steps:
// 1. Iterate from arr[1] to arr[n] over the array.
// 2. Compare the current element (key) to its predecessor.
// 3. If the key element is smaller than its predecessor, compare it to the elements before.
//    Move the greater elements one position up to make space for the swapped element.
// 4. Repeat until the array is sorted.



#include<bits/stdc++.h>
using namespace std;
void swp(int *a , int *b){
    *a ^= *b ^= *a ^= *b ;
}
void insertionSort(int *arr , int n){
    int i, key, j;
    for (i = 1; i < n; i++){
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key){
            swp(&arr[j + 1],&arr[j]);
            j = j - 1;
        } 
    }
}
int main(){
    int n ;
    cin >> n ;
    int a[n] ;
    for(int i = 0 ; i < n ; i++) cin >> a[i] ;
    insertionSort(a , n) ;
    for(int i = 0 ; i < n ; i++) cout << a[i] << " " ;
}