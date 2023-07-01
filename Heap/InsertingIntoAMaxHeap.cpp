//This representation uses Array representation 
//For theory part - See note khata

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

//this implementation uses array indexing starts from 0 to n-1 
//and formula - parentptr = (childptr-1)/2 ;



//time complexity of heapInsert function :same as the height of the tree
//TC : O(logn)      //base 2 log

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




//this implementation uses array indexing starts from 1 to n-1 
//and formula - parentptr = childptr/2 ;
void heapInsert2(int ar[] , int i) {

    int temp = ar[i] ;
    int childptr = i ; 
    int parentptr = i/2 ;  
    while(childptr > 1 ){   //this will end when childptr greater than 1 
        if(ar[parentptr] < ar[childptr]) {
            swap(ar[parentptr] , ar[childptr]) ;
            childptr = parentptr ;
            parentptr = childptr/2 ;      
        }
        else break;  
    } 

}
void print(int arr[] , int n){
    for(int i = 0 ; i <n ; i++) cout<<arr[i]<<" " ; 
    cout<<"\n" ; 
}
int main(){

    cout<<"Enter the maximum number of element in a heap: " ; 
    int n; cin>>n ;

    int heap[n] ={0} ; 
    for(int i = 0 ; i < n; i++){   //to use heapInsert2 function , you must start taking input from i = 1 ; 
        cin>>heap[i] ; 
        heapInsert1(heap , i) ; 
        print(heap , n ) ;
    } 

    
}

//Terminal using heapInsert1 function :

// Enter the maximum number of element in a heap: 10
// 30
// 30 0 0 0 0 0 0 0 0 0 
// 20
// 30 20 0 0 0 0 0 0 0 0 
// 15
// 30 20 15 0 0 0 0 0 0 0 
// 5
// 30 20 15 5 0 0 0 0 0 0 
// 10
// 30 20 15 5 10 0 0 0 0 0
// 12
// 30 20 15 5 10 12 0 0 0 0
// 6
// 30 20 15 5 10 12 6 0 0 0
// 11
// 30 20 15 11 10 12 6 5 0 0
// 40
// 40 30 15 20 10 12 6 5 11 0
// 50
// 50 40 15 20 30 12 6 5 11 10


// Terminal using heapInsert2 function:
// Enter the maximum number of element in a heap: 11
// 30
// 0 30 0 0 0 0 0 0 0 0 0 
// 20
// 0 30 20 0 0 0 0 0 0 0 0 
// 15
// 0 30 20 15 0 0 0 0 0 0 0 
// 5
// 0 30 20 15 5 0 0 0 0 0 0 
// 10
// 0 30 20 15 5 10 0 0 0 0 0
// 12
// 0 30 20 15 5 10 12 0 0 0 0
// 6
// 0 30 20 15 5 10 12 6 0 0 0
// 11
// 0 30 20 15 11 10 12 6 5 0 0
// 40
// 0 40 30 15 20 10 12 6 5 11 0
// 50
// 0 50 40 15 20 30 12 6 5 11 10

//As you can see , both results are same 



