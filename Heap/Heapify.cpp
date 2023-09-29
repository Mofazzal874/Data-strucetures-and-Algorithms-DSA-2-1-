//heapify is a faster method of creating a heap 

//Time complexity : O(n) 
//whereas in the previous method of creating heap , it takes O(nlogn) time



#include<bits/stdc++.h>
using namespace std;
typedef long long ll;




// for n elements or a complete binary tree with n nodes , there are almost n/2 numbers of leaf nodes 
// and in the given complete binary tree array from node (floor(n/2)+1) to n will be leaf node..so actually we can start from 
//  index = n/2 to calculate the heap building process 
//  in this way , the heapify will take O(n) time.

void heapify(int arr[] , int n )  {

    int parentptr = n-1 ;
    int childptr = 2*parentptr+1 ;  
    while(parentptr >= 0){
        if(childptr >= n) parentptr-- ; 
        else {
             if(arr[childptr+1] > arr[childptr]) childptr = childptr+1 ; 
             if(arr[parentptr]< arr[childptr]) swap(arr[parentptr] , arr[childptr]) ;
             parentptr-- ;
             childptr = 2*parentptr+1 ;     
        }
    }
}


void print(int arr[] , int n ){
    for(int i = 0 ; i < n ;i++){
        cout<<arr[i] <<" " ; 
    }
    cout<<"\n" ; 
}
int main(){
    
    int a[] = { 5, 10, 30, 20, 35, 40, 15} ; 
    heapify(a, 7) ; 
    print(a,7);
    
}