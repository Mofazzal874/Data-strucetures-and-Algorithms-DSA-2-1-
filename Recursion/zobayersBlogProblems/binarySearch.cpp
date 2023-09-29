/*Implement binary search recursively, i.e. given an array of sorted integers, find a query integer from it. Input format: first n, the number of elements. Then n integers. Then, q, number of query, then q integers. Output format: for each of the q integers, print its index (within 0 to n-1) in the array or print 'not found', whichever is appropriate.
Input:
5
1 2 3 4 5
2
3 -5
Output:
2
not found
*/
#include<bits/stdc++.h>
using namespace std;
#define int long long
template<typename T>
using min_heap = priority_queue<T , vector<T> , greater<T>> ; //to make minHeap. min_heap<type> name
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);


string binarySearch(vector<int>&v ,int l , int h ,  int s){

    if(l>h) return "not found" ;
    int mid = l+(h-l)/2; 
    if(v[mid]== s) return to_string(mid);
    else if(s>v[mid]) return binarySearch(v , mid+1 , h , s) ; //search in the right
    else return binarySearch(v , l , mid-1,s) ; //search in the left   
}

int32_t main(){
    
    int n ;cin>>n ; 
    vector<int> v(n) ; 
    for(auto &it :v) cin>>it ;
    if(!is_sorted(v.begin() , v.end())&& !is_sorted(v.rbegin(), v.rend())) sort(v.begin() , v.end()); //if not sorted than sort it ; 
    int q ; cin>>q ; 
    while(q--){
        int s ; cin>>s ; 
        cout<<binarySearch(v ,0 , n-1, s)<<endl;
    }
}