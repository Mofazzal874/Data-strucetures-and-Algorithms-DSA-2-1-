/*
This is also same problem but Here you have to return the total no of subsequences whom summation is equal to k.

INPUT:
3
1 2 1
2
OUPUT:
2

Solving Steps:
This types of problems is very common in Dynamic Programming. The basic structure of this type of recursion is like_>

int f(){

    base case{
        return 1 -> if condition satisfies
        return 0 -> if condition does not satisfy
    }
    l = f() ; 
    r = f() ; 
    return l+r ; //L+r is the total number of count


    //Note:ON the Above structure , there is only two recursion calls. what if there are no. of recursion calls?
    This is also simple.

    base case 
    int s = 0 ;
    for(int i to-> n)
    s+=f() ;   //just add up all the recursion calls;
    return s ;

    //You'll see the second type of question in N-queen problems.  

}
*/


#include<bits/stdc++.h>
using namespace std;
#define int long long
template<typename T>
using min_heap = priority_queue<T , vector<T> , greater<T>> ; //to make minHeap. min_heap<type> name
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);

int pSub(vector<int>&arr , int n ,int k  , int curIndx , int sum){


    if(curIndx>=n){
        if(sum==k) return 1 ; 
        else return 0 ; 
    }
    //take the current element
    sum+=arr[curIndx] ; 
    int l = pSub(arr, n , k,curIndx+1 , sum) ; 
    //do not take current element
    sum-=arr[curIndx] ;
    int r = pSub(arr, n , k ,  curIndx+1 , sum) ; 
    return l+r; //return the count
}

int32_t main(){


    int n ; cin>>n ; 
    vector<int> arr(n) ; 
    for(auto &it:arr) cin>>it;
    int k ; cin>>k ; 
    vector<int> ans ; 
    cout<<pSub(arr , n ,k , 0 , 0 ) ;
    
}