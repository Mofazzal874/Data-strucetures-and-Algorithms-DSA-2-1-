#include<bits/stdc++.h>
using namespace std;
#define int long long
template<typename T>
using min_heap = priority_queue<T , vector<T> , greater<T>> ; //to make minHeap. min_heap<type> name
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);


int gcd(int a , int b){
    if(b==0|| a == b) return a ; 
    return gcd(b,a%b) ; 
}

int32_t main(){


    int n ; cin>>n ;
    vector<int> v(n);
    for(int &it:v) cin>>it ; 
    int ans=v[0] ;
    for(int i = 1; i < n ; i++){
        ans = gcd(ans , v[i]) ; 
    }
    cout<<ans<<endl;
    
}