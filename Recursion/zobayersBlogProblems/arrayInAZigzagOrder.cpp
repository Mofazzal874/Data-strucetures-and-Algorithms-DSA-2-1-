/*Write a recursive function to print an array in the following order. [0] [n-1] [1] [n-2] ......... ......... [(n-1)/2] [n/2]
Input:
5
1 5 7 8 9
Output:
1 9
5 8
7 7
*/



#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int,int>
template<typename T>
using min_heap = priority_queue<T , vector<T> , greater<T>> ; //to make minHeap. min_heap<type> name
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);

void fun(int i , int n , int a[]){
    
    if(i > n) return ; 
    cout<<a[i]<<" "<<a[n-1]<<"\n" ; 
    fun(i+1 , n-1 , a) ; 

}

/*another tweak:
to print the answer in reverse order , like:
7 7 
5 8 
1 9
just call the cout part after the function call 
like:
fun(i+1 , n-1 , a) ;
cout<<a[i]<<" "<<a[n-1]<<"\n" ;
*/


int32_t main(){

    int n ;cin>>n ; 
    int a[n] ; 
    for(int i = 0 ; i < n ; i++) cin>>a[i] ; 
    fun(0 , n , a) ; 

    
 
}