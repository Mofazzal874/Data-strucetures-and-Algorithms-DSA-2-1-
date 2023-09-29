#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int partition(int a[] ,int low ,int  high){
 //taking left first element as pivot
    
    int pivot = a[low] ; 
    int i = low , j = high ; 
    while(i < j){
        while(a[i] <= pivot && i <= high-1 ) {i++ ;} 
        while(a[j] > pivot && j >= low+1) {j-- ;} 
        if(i < j)  swap(a[i] , a[j]) ;
    }
    swap(a[low] , a[j]) ;
    return j ; //returning the index of pivot in the sorted array 

}
void quickSort(int a[] , int low , int high){

    if(low< high){
        int pIndx = partition(a, low , high) ;
        quickSort(a , low , pIndx - 1) ; 
        quickSort(a , pIndx + 1 , high) ;  

    }
}
int main(){
    int n ;cin>>n; 
    int array[n] ; 
    for(int i = 0 ; i < n ; i++){
        cin>>array[i] ;
    }
    quickSort(array , 0 , n-1) ;
    for(int i = 0 ; i < n ; i++){
        cout<<array[i]<<" " ;
    }
    
}