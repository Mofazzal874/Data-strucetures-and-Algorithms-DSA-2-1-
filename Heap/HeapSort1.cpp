//using MaxHeap 
//if you use maxheap , you will get a ascending ordered array

// algorithm:
// i. firstly , make a maxHeap out of the given array of n elements.
// ii. lastly , run deletion operation in the maxHeap and copy every deleted element in the 
// available space from right hand side

//Time complexity analysis:
//total insertion for n elements : O(nlogn)  //every insertion takes logn time 
//total deletion for n elements : O(nlogn)   //every deletion takes logn time
//Time complexity: O(2nlogn) = O(nlogn)


#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void heapInsert(int arr[] , int i){

    int childptr = i ; 
    int parentptr = (i-1)/2 ; 
    while(childptr > 0 ){
        if(arr[childptr] > arr[parentptr]) {
            swap(arr[childptr] , arr[parentptr]) ;
            childptr = parentptr ; 
            parentptr = (childptr-1)/2; 

        }
        else break; 
    }
}

void heapDelete(int ar[] , int index) {


    int x = ar[0] ; 
    ar[0] = ar[index] ; 
    int i = 0 ; 
    int j = 2*i+1 ; 

    while(j < index){
        if(ar[j+1] > ar[j]) j = j + 1; 

        if( ar[j] > ar[i]){
            swap(ar[j] , ar[i]) ;
            i =  j ; 
            j = 2*i+1 ; 
        }
        else break; 
    }
    ar[index] = x ; 

}

void heapSort(int arr[] , int n ){

    for(int i = n-1 ; i >= 0 ; i--){
        heapDelete(arr, i) ; 
    }
}

void print(int arr[] , int n ){

    for(int i = 0 ; i < n ;i++){
        cout<<arr[i]<<" "  ; 
    }
    cout<<"\n" ; 
}


int main() {

    cout<<"Enter the number of elements that you want to sort: " ; 
    int n ; cin>>n ; 
    int heap[n] ; 
    cout<<"Enter elements : " ; 
    for(int i = 0 ; i < n ; i++){
        cin>>heap[i] ; 
        heapInsert(heap , i) ;
    }
    heapSort(heap ,n) ; 
    print(heap,n) ; 
}

//Terminal :

// test Case-01:

// Enter the number of elements that you want to sort: 7
// Enter elements : 5 30 35 40 10 25 15
// 5 10 15 25 30 35 40

//30 20 15 5 10 12 6 11 40 50
//test case-02:

// Enter the number of elements that you want to sort: 10
// Enter elements : 30 20 15 5 10 12 6 11 40 50
// 5 6 10 11 12 15 20 30 40 50

