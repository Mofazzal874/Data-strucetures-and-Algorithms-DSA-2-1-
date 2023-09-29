/*
This problem is same as "printtingSubsequences.cpp" , only diff. is that 
you are given a number k  and print the subsequences whose summation is equal 
k.
first line-no of elements 
second line - elements input
third line - k 
INPUT:
3
1 2 1
2
OUTPUT:
1 1
2
*/

#include<bits/stdc++.h>
using namespace std;
#define int long long
template<typename T>
using min_heap = priority_queue<T , vector<T> , greater<T>> ; //to make minHeap. min_heap<type> name
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);



void pSub(vector<int>&arr , int n ,int k ,  vector<int> &ans , int curIndx , int sum){


    if(curIndx>=n){
        if(sum==k){
            for(auto it:ans) cout<<it<<" " ; 
            cout<<endl;
            return ; 
        }
        else return ;//no need to do anything , just return.
    }
    //take the current element
    ans.push_back(arr[curIndx]) ; 
    sum+=arr[curIndx] ; 
    pSub(arr, n , k , ans , curIndx+1 , sum) ;
    //do not take current element
    ans.pop_back() ;
    sum-=arr[curIndx] ;
    pSub(arr, n , k , ans , curIndx+1 , sum) ;
}

int32_t main(){

    int n ; cin>>n ; 
    vector<int> arr(n) ; 
    for(auto &it:arr) cin>>it;
    int k ; cin>>k ; 
    vector<int> ans ; 
    pSub(arr , n ,k ,  ans , 0 , 0 ) ;  
}