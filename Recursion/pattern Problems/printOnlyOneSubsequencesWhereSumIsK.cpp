/*
This problem is similar to "printSubsequencesWhereSumIsK.cpp".But Here you 
Have to stop as soon as you find a single subsequence which satisfies the 
codition(sum==k) and print it and no need to print all the subsequences.

INPUT:
3
1 2 1 
2

OUTPUT:
1 1   or 2 (It can be any one of them,doesn't matter)
*/

/*
Idea : 
you may use flag that can be used like -  if flag == false, then after satisfying the conditon
 (curIndx>=n) , you can print the subsequence and make the flag true. then for every recursion call,
 it will be checked if the flag is true , then you won't print anything. just finish all the function call.
 But this method is not effective and effecient as you are stopping as soon as you find the answer.Rather 
 you are finishing all the function calls then returning to main.So it's time complexity will not be 
 optimized.

 Here is the code of the above implementation:

```
 int flag = false ;//global variable
void pSub(vector<int>&arr , int n ,int k ,  vector<int> &ans , int curIndx , int sum){


    if(curIndx>=n){
        if(sum==k && flag == false){
            for(auto it:ans) cout<<it<<" " ;
            flag = true ;  
            cout<<endl;
            return ; 
        }
        else return ;//no need to do anything , just return.
    }
    //take the current element
    ans.push_back(arr[curIndx]) ; 
    sum+=arr[curIndx] ; 
    pSub(arr, n , k , ans , curIndx+1 , sum) ;
    //do not take current element
    ans.pop_back() ;
    sum-=arr[curIndx] ;
    pSub(arr, n , k , ans , curIndx+1 , sum) ;
}
```

the problems with this implementation is:using of global variable and 
time complexity is not optimized
 
 



 So what can you do???????????????????
 The idea is to use the true or false in function returning time.
You need to stop all recursion as soon as find the answer.
Implementation:
 */

#include<bits/stdc++.h>
using namespace std;
#define int long long
template<typename T>
using min_heap = priority_queue<T , vector<T> , greater<T>> ; //to make minHeap. min_heap<type> name
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);


bool pSub(vector<int>&arr , int n ,int k ,  vector<int> &ans , int curIndx , int sum){


    if(curIndx>=n){
        if(sum==k){
            for(auto it:ans) cout<<it<<" " ; 
            cout<<endl;
            return true; 
        }
        else return false;//no need to do anything , just return.
    }
    //take the current element
    ans.push_back(arr[curIndx]) ; 
    sum+=arr[curIndx] ; 
    if(pSub(arr, n , k , ans , curIndx+1 , sum)) return true ; //Here true means , we found the answer in some
                                                //recursion call , all we need to do is to return 
    //do not take current element
    ans.pop_back() ;
    sum-=arr[curIndx] ;
    if(pSub(arr, n , k , ans , curIndx+1 , sum)) return true; //same as before

    return false ; //that means we still didn't find any suitable answer , keep searching 
}

int32_t main(){


    int n ; cin>>n ; 
    vector<int> arr(n) ; 
    for(auto &it:arr) cin>>it;
    int k ; cin>>k ; 
    vector<int> ans ; 
    pSub(arr , n ,k ,  ans , 0 , 0 ) ;
    
}