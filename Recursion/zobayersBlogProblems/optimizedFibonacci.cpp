//this code contains the recursive and iterative process of calculationg fibonacci series
//also include DP 
//source: shafayetsplanet.com
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int,int>
template<typename T>
using min_heap = priority_queue<T , vector<T> , greater<T>> ; //to make minHeap. min_heap<type> name
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);


int  recursiveFibo(int n ){

    static vector<int> calc(100,-1) ;
    if( n==0|| n==1) return n;  
    if( calc[n]!= -1 ) return calc[n] ; 
    calc[n] = recursiveFibo(n-1)+recursiveFibo(n-2); 
    return calc[n] ;
}

int iterativeFibo(int n){
    

    vector<int> calc(100,-1) ; 
    //lets store the results that we know of fibonacci series in the calc vector
    calc[0] = 0 ; 
    calc[1] = 1 ; 
    for(int i = 2 ; i <= n ; i++){
        calc[i] = calc[i-1] + calc[i-2] ;
    }
    return calc[n] ; 
}

int32_t main(){
    int n ;cin>>n ; 
    cout<<recursiveFibo(n);
    cout<<iterativeFibo(n) ; 
}