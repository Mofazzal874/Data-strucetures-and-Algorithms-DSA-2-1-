/*
Write a recursive function that finds the gcd of two non-negative integers.
Input:
25 8895
Output:
5
*/
/*
theory part:
From euclid division algorithm:
i.GCD of a & 0 is a 
ii.GCD of  a  & b = GCD of b & a%b
*/
#include<bits/stdc++.h>
using namespace std;
#define int long long
template<typename T>
using min_heap = priority_queue<T , vector<T> , greater<T>> ; //to make minHeap. min_heap<type> name
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);


//recursive
int gcd1(int a , int b){

    if(b==0 || a==b) return a ; 
    return gcd1(b,a%b) ; 
}

//iterative
int gcd2(int a , int b){

    if(a==0||b==0 || a==b) return max(a,b) ; 
    else{
        while(b) {
            int t = b ; 
            b = a%b ; 
            a = t; 
        }
        return a ;
    }
}


//Binary algo
int gcd3(int a, int b){
    while(b) b ^= a ^= b ^= a %= b; 
    return a ; 
}
int32_t main(){

    int a , b ; cin>>a>>b ; 
    cout<<gcd1(a,b) ; 
    
}