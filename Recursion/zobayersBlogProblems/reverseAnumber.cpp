/*
Write a recursive solution to get the reverse of a given integer. Function must return an int
Input:
123405
Output:
504321
*/
#include<bits/stdc++.h>
using namespace std;
#define int long long
template<typename T>
using min_heap = priority_queue<T , vector<T> , greater<T>> ; //to make minHeap. min_heap<type> name
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);


int revNum(int n , int rev ){

    if(n==0) return rev ; 
    rev = rev*10 + n%10 ; 
    return revNum(n/10 , rev) ;  
}

int32_t main(){
    int n ; cin>>n ; 
    cout<<revNum(n,0 )<<endl;
}