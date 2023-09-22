/*
Write a recursive solution to print the polynomial series for any input n: 1 + x + x2 + ................. + xn-1
Input:
5
Output:
1 + x + x^2 + x^3 + x^4
*/


#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int,int>
template<typename T>
using min_heap = priority_queue<T , vector<T> , greater<T>> ; //to make minHeap. min_heap<type> name
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);



//this is a backward recursion
void fun(int i , int n ){

    if(i== 0) {
        cout<<1 ; 
        return ;
        }    
    fun(i-1,n) ;
    if(i< n){
        if(i==1) cout<<" + x" ;  
        else cout<<" + x^"<<i ;
    }
     
}


//alternatively
//forward recursion
void fun2(int i, int n)
{
    if(i<n)
    {
        if(i==0) printf("1");
        else
        {
            printf(" + x");
            if(i>1) printf("^%d", i);
        }
        fun2(i+1, n);
    }
}


int32_t main(){
    int n ;cin>>n ; 
    fun(n , n) ;
    //alternative fun2
    //fun2(0 , n) ; 
}