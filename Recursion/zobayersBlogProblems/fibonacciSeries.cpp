#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//iterative function for fibonacci series
//time complexity: O(n)
int fibIterative(int n){
    int sum0 = 0 , sum1 = 1 ; 
    int next ; 
    if(n<=1) return n ; 

    for(int i = 2 ; i<= n ;i++){
        next = sum0+sum1 ;
        sum0 = sum1 ; 
        sum1 = next ;
    }
    return next ;  

}

//recursive function for fibonacci series

int fib(int n){
    if( n<= 1) return n ; 
    else return fib(n-2) +fib(n-1) ;
}
//optimized code for Fibonacci series
int F[10] ;
int fibOptimized(int n){ 
    if(n <= 1) {
        F[n] = n ; 
        return n;
    } 
    else{
        if(F[n-2] == -1) F[n-2] = fibOptimized(n-2) ; 
        if(F[n-1] == -1) F[n-1] = fibOptimized(n-1) ;
        F[n] =F[n-2] +F[n-1];
        return F[n];
    }
}
int main(){
    cout<<"Enter the term number: " ;
    int n ; cin>>n; 
    cout<<fib(n);
    cout<<endl;
    cout<<fibIterative(n) ; 
    cout<<endl;
    for(int i = 0 ; i< 10 ;i++){
        F[i] = -1; 
    }
    cout<<fibOptimized(n);  
}