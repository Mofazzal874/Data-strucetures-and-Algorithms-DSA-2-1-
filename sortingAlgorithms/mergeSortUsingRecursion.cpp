#include<bits/stdc++.h>
using namespace std ;

//conquer part
void mergee(int arr[] , int beg , int mid , int ed){

    int n1 = mid - beg + 1;
    int n2 = ed - mid ;
    int left[n1] , right[n2] ;
    
    for(int i = 0 ; i < n1 ; i++) left[i] = arr[i+beg] ;
    for(int i = 0 ; i < n2 ; i++) right[i] = arr[i+mid+1] ;
    
    int idx1 = 0 ;
    int idx2 = 0 ;
    int idx = beg ;

    while(idx1 < n1 && idx2 < n2){
        if(left[idx1] <= right[idx2]){
            arr[idx] = left[idx1] ;
            idx1++ ;
        }
        else{
            arr[idx] = right[idx2] ;
            idx2++ ;
        }
        idx++ ;
    }

    while(idx1 < n1){
        arr[idx] = left[idx1] ;
        idx1++ ;
        idx++ ;
    }
    while(idx2 < n2){
        arr[idx] = right[idx2] ;
        idx2++ ;
        idx++ ;
    }
}

//divide part
void mergeSort(int arr[] , int beg , int ed){
    int mid = (ed + beg) / 2 ;
    if(beg >= ed) return ;

    mergeSort(arr , beg , mid) ;
    mergeSort(arr , mid+1 , ed) ;
    mergee(arr , beg , mid , ed) ;
}

int main(){
    int n ; cin >> n ;
    int arr[n] ;
    for(int i = 0 ; i < n ; i++) cin >> arr[i] ;
    mergeSort(arr ,0 , n-1) ;
    for(int i = 0 ; i < n ; i++) cout << arr[i] << " " ;
}