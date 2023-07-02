#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

//time complexity of heapInsert function :same as the height of the tree
//TC : O(logn) [base 2 log]  //for every insertion 
//TC: O(nlogn) //for n elements 
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

void print(int arr[] , int n){
    for(int i = 0 ; i <n ; i++) cout<<arr[i]<<" " ; 
    cout<<"\n" ; 
}



//time complexity(TC): O(logn)    (base 2 log)   , for every deletion process 
//TC : O(nlogn) for n elements 
void heapDelete(int* arr , int n){

    int x = arr[0] ; //copying the max element of the heap in a variable called x so that we can put it back at the last position of the array 
                    //after deletion is complete

    arr[0] = arr[n-1] ; //putting the last element of the heap in first position 


    int i = 0;   // parent node 
    int j = 2*i+1 ;  //left child of i ; as we are taking 0 indexed array , so we should use 2*i+1 formula , 
                    //for 1 indexed array , you can simply use j = 2*i to find the left child of i  
    while( j < n-1){
        if(arr[j+1] > arr[j]) j = j+1; //if right child is greater than left child , then j should point to right child 

        if(arr[i] < arr[j]) {
            swap(arr[j] , arr[i]) ; //if the j pointed element is greater than its mother element , then swap ; 
            i = j ;   // i should go to j's place and again calculate from there 
            j = 2*j+1 ; //left child of i ;  

        }
        else {   //arra[i]>= arra[j] , you don't need to do anything after that. Because beyond that point of i , it is already heapified 
                    //so no need to continue the loop
                break; 
        }
    }

    //from 0 to n-2 is heapified .but arr[n-1] is not in the heap . we just store it to make heap sort 
    arr[n-1] = x ; //putting back x in the last position 
}
int main(){

    cout<<"Enter the maximum number of element in a heap: " ; 
    int n; cin>>n ;

    int heap[n] ={0} ; 
    for(int i = 0 ; i < n; i++){  
        cin>>heap[i] ;      
        heapInsert1(heap , i) ;
    }
    heapDelete(heap , n);
    print(heap , n); 
    
    //you can also use the heapDelete function in a loop,then you will get element in ascending order from a max heap and in a descending order in min heap 
    //This is called heap sort 

}


//terminal : 

//test case-01:

// Enter the maximum number of element in a heap: 7
// 40 35 30 15 10 25 5
// 35 15 30 5 10 25 -1


// test case-02:
// Enter the maximum number of element in a heap: 10
// 30 20 15 5 10 12 6 11 40 50
// 40 30 15 20 10 12 6 5 11 -1



