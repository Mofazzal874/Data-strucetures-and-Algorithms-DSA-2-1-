/*
Write a recursive solution to find the second maximum number from a given set of integers.
Input:
5
5 8 7 9 3
Output:
8
*/


#include<bits/stdc++.h>
using namespace std;
#define int long long
template<typename T>
using min_heap = priority_queue<T , vector<T> , greater<T>> ; //to make minHeap. min_heap<type> name
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);






int secondMax(vector<int> &v ,int n  ,  int i ,int max , int sMax){

    if(i==n) return sMax ; 
    if(v[i]>max) return secondMax(v,n , i+1 ,v[i] , max) ;  //if the current element is greate than max , updating the max and making the max as second Max now .  
    else if(v[i]> sMax && v[i]!=max) return secondMax(v ,n ,i+1 , max , v[i]) ; //if this case , we are checking if the current element 
                                                                                //is greater than second Max and also not equal to max ,
                                                                                //so that no duplicate occurs
    return secondMax(v,n ,  i+1 , max , sMax) ;  

}

int32_t main(){

    int n ;cin>>n ; 
    vector<int>v(n) ; 
    for(auto &it:v) cin>>it ; 
    cout<<secondMax(v, n ,0 ,INT_MIN,INT_MIN)<<endl;
    
}