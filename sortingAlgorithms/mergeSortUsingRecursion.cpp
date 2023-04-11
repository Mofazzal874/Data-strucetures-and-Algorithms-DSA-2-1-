#include <bits/stdc++.h>
using namespace std ;
 
void merg(int *arr , int s , int e){
 
    int mid = (s+e)/2 ;
    int len1 = mid - s+1 ;
    int len2 = e - mid ;
    int *first = new int(len1) ;
    int *second = new int(len2) ;
    int k = s ;
    for( int i = 0 ; i < len1 ; i++){
        first[i] = arr[k++] ;
    }
    k = mid+1 ;
    for( int i = 0 ; i < len2 ; i++){
        second[i] = arr[k++];
    }
    int indx1 = 0 ;
    int indx2 = 0 ;
    k= s ;
    while(indx1 < len1 && indx2 < len2){
        if(first[indx1] < second[indx2]){
            arr[k++] = first[indx1++] ;
        }
        else{
            arr[k++] = second[indx2++] ;
        }
    }
    while(indx1 < len1){
        arr[k++] = first[indx1++] ;
    }
    while(indx2 < len2){
        arr[k++] = second[indx2++] ;
    }
 
}
 
void mergeSort(int *arr , int s , int e){
 
    if( s >= e) return ;
    int mid = (s+e)/ 2 ;
    mergeSort(arr, s , mid) ;
    mergeSort(arr , mid+1 , e) ;
    merg(arr , s, e ) ;
 
}
 
int main() {
    int n ; cin>>n ;
    int arr[n] ;
    for( int i = 0 ; i < n ; i++){
        cin>>arr[i] ;
    }
    mergeSort(arr , 0 , n - 1 ) ;
    for( int i = 0 ; i < n ; i++){
        cout<<arr[i]<<" " ;
    }
}