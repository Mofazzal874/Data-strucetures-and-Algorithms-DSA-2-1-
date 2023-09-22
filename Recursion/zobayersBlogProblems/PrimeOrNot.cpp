/*
Write a recursive program to determine whether a given integer is prime or not.
Input:
49
999983
1
Output:
not prime
prime
not prime
*/
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int,int>
template<typename T>
using min_heap = priority_queue<T , vector<T> , greater<T>> ; //to make minHeap. min_heap<type> name
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);


bool isPrime(int i , int n){
    
    if(n <= 1 || !(n&1)) return false ;  
    if(i*i <= n){
        if(!(n%i)) return false ; 
        return isPrime(i+1 , n) ; 
    }
    return true ; 
}

int32_t main(){

    int n ;
    while(cin>>n){ 
        if(isPrime(2,n)) cout<<"prime\n" ; 
        else cout<<"not prime\n" ; 
    }

    
 
}