/*
problem source: strivers recursion series lecture -06
subsequence is a subset of a given sequence but in a sequential order . The sequence must not be broke.
for example:
for a sequence {3,1,2}
subsequences are ->{3,1,2} , {3,1} , {3,2} , {3},{1,2},{1},{2},{} .So total 8 subsequences will be there for an array of 3 elements.
All of the above subsets are subsequences of the original sequence as they come as the same order as the main sequence.But {2,3} , {1,2,3} etc
are not subsequences as they don't follow the order.

Your task is to find all the subseqence of a given array in a recursive function.
input:
3 
3 1 2
output:
3 1 2
3 1
3 2
3
1 2
1 
2 

*/

#include<bits/stdc++.h>
using namespace std;
#define int long long
template<typename T>
using min_heap = priority_queue<T , vector<T> , greater<T>> ; //to make minHeap. min_heap<type> name
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);

void printSub(vector<int>&v, vector<int>& arr , int n ,  int curIndex){

    if(curIndex>= n){
        for(auto it:v) cout<<it<<" " ; 
        cout<<endl;
        return ;
    }
    //you have two options:
    //01.take the element at current position
    v.push_back(arr[curIndex]) ; 
    printSub(v , arr ,  n , curIndex+1);
    //02.not take the element at current position
    v.pop_back(); 
    printSub(v ,arr ,  n , curIndex+1);


}

int32_t main(){
    int n;cin>>n; 
    vector<int> arr(n) ; 
    for(auto &it:arr) cin>>it;
    vector<int>v ; 
    printSub(v , arr, n ,0); 
    
}