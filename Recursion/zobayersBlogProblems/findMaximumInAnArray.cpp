/*
Suppose you are given an array of integers in an arbitrary order. Write a recursive solution to find the maximum element from the array.
Input:
5
7 4 9 6 2
Output:
9
*/

#include<bits/stdc++.h>
using namespace std;
#define int long long
template<typename T>
using min_heap = priority_queue<T , vector<T> , greater<T>> ; //to make minHeap. min_heap<type> name
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);



int maximum1(vector<int>&v , int i , int max){

    if(i==0) return max;
    if(v[i]>max) return maximum1(v,i-1 , v[i]) ;
    return maximum1(v,i-1,max) ;  
}

//alternative
int maximum2(vector<int>&v , int n , int i  , int max ){
    if(i==n) return max ; 
    if(v[i]>max) return maximum2(v , n , i+1 , v[i]) ;
    return maximum2(v ,n , i+1 , max) ; 
}

int32_t main(){
    int n  ; cin>>n ;
    vector<int> v(n) ; 
    for(int &it:v) cin>>it; 
    //cout<<maximum(v , n-1 , v[n-1]) ;
    cout<<maximum2(v , n , 0 , INT_MIN)<<endl;
}