#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


void heapInsert1(int ar[] , int i) {

    int temp = ar[i] ;
    int childptr = i ; 
    int parentptr = (i-1)/2 ;  
    while(childptr > 0 ){
        if(ar[parentptr] < ar[childptr]) {
            swap(ar[parentptr] , ar[childptr]) ;
            childptr = parentptr ;
            parentptr = (childptr-1)/2 ;      
        }
        else break;  
    } 

}

void createHeap(int arr[] , int n , int last ){

    for(int i = 1 ; i <last ; i++){
        heapInsert1(arr , i ) ; 
    }
}

void print(int arr[] , int n){
    for(int i = 0 ; i <n ; i++) cout<<arr[i]<<" " ; 
    cout<<"\n" ; 
}

int main(){


    int a[] = { 10, 20, 30, 25, 5, 40, 35} ;
    cout<<"Till which index you want to make heap: " ; 
    int last ; cin>>last ;  
    createHeap(a , 7 , last ) ;
    print(a , 7) ;     
}