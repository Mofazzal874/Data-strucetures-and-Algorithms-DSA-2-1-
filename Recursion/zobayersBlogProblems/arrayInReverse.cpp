//Reversing an array recursively
/*input:
5
69 87 45 21 47
output:
47 21 45 87 69
*/


#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int,int>
template<typename T>
using min_heap = priority_queue<T , vector<T> , greater<T>> ; //to make minHeap. min_heap<type> name
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);



//01
//reverse an array without printing .Means you have to reverse it in the same array that is given.
// You can not take any additional array
void fun1(int i , int n , int a[] ){

    if(i>n) return ;
    swap(a[i],a[n-1]) ;
    fun1(i+1 , n-1 ,a) ; 
}
//02
//you can use an extra variable
void fun2(int i  , int n , int a[]){
    if(i== n) return ; 
    fun2(i+1 , n , a) ; 
    cout<<a[i]<<" " ;
}
//03
//you can not use any extra variables
void fun3(int n , int a[]){
    if(n<= 0 ) return  ; 
    cout<<a[n-1]<<" " ; 
    fun3(n-1 , a) ; 
}

int32_t main(){

    int n ; cin>>n ; 
    int a[n] ; 
    for(int i = 0 ; i < n ;i++) cin>>a[i] ;
    //comment the below 2 lines to implement first recursive function 
    // fun1( 0 , n , a) ;
    // for(auto i:a) cout<<i<<" " ;
    ////comment the below 1 lines to implement second recursive function
    // fun2(0 , n , a) ;
    //comment the below 1 lines to implement 3rd recursive function
    fun3(n ,a) ; 


 
}