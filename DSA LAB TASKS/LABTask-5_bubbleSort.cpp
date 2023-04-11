#include <bits/stdc++.h>
using namespace std;
 
void swp(int &a , int &b){
    a = a+ b ;
    b = a- b ;
    a = a- b ;
}



void swapp(int &a , int &b){
  
  a = a^b ; 
  b = b^a  ;
  a = a^b ;
}
  
void bubbleSort(int ara[] , int n) {
 
    for(int i = 0 ; i < n - 1 ; i++){
 
        for(int j = 0 ; j < n - 1- i ; j++){
            if(ara[j] > ara[j+1]){
                swp(ara[j]  , ara[j+1]) ;
            }
        }
    }
}
 
 
 
int main(){
 
    int array[20] ;
    int n ; cin>>n ;
    for(int i = 0 ; i < n ; i++){
        cin>>array[i] ;
    }
    bubbleSort(array , n) ;
    for(int i = 0 ; i < n ; i++){
        cout<<array[i]<<" " ;
    }
 
    }
