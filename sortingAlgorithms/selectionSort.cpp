#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void swp(int &a , int &b){
    a = a+ b ;
    b = a- b ;
    a = a- b ;
}

void selectionSort(int a[] , int n){
 
    for( int i = 0 ; i < n-1 ;i++){
       int  min_indx = i ; 
        for( int j = i+1 ; j < n ; j++){
            if(a[j] < a[min_indx]){
                min_indx = j ; 
            }
        }
        if(min_indx != i){          //if min_indx == i , that means minimum number is at its right position,
                                    //no need to swapping
            swp(a[i] , a[min_indx]) ; 
            
        } 
    }
}
int main(){

     int n ;cin >> n ;
    int array[n] ;
    for(int i = 0 ; i < n ; i++) cin >> array[i] ;
    selectionSort(array , n) ;
    for(int i = 0 ; i < n ; i++) cout << array[i] << " " ;
    
}