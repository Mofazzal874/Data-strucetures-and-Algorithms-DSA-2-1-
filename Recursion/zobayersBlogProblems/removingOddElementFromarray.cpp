/*
Write a recursive program to remove all odd integers from an array. You must not use any 
extra array or print anything in the function. Just read input, call the recursive function, 
then print the array in main().(you should the print the even element just same as the 
incoming order in the input array)
Input:
6
1 54 88 6 55 7
Output:
54 88 6
*/


#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int,int>
template<typename T>
using min_heap = priority_queue<T , vector<T> , greater<T>> ; //to make minHeap. min_heap<type> name
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);


void fun(int i ,int j ,  int &n , int a[]){
//j will point the odd element 
//i will point the current element

    if(i == n){
        n = j ;
        return ;  
    }
    if(!(a[i]&1)) a[j++] = a[i] ; 
    fun(i+1 , j , n , a) ;
}

int32_t main(){

    int n ; cin>>n  ; 
    int a[n] ; 
    for(int i = 0 ; i < n ;i++) cin>>a[i] ; 
    fun(0 , 0 , n,a) ; 
    for(int i = 0 ; i < n ;i++) cout<<a[i]<<" " ;
    cout<<endl;
    cout<<n<<endl;
 
}