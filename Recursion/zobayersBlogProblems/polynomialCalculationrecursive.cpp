/*Write a recursive solution to evaluate the previous polynomial for any
 given x and n. Like, when x=2 and n=5, we have 1 + x + x2 + ................. + xn-1 = 31
Input:
2 5
Output:
31
*/
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int,int>
template<typename T>
using min_heap = priority_queue<T , vector<T> , greater<T>> ; //to make minHeap. min_heap<type> name
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);




//Backward Recursion
int fun1(int i , int x , int n , int &sum){ //you can use the sum as static variable or you have to take sum variable 
                                            //as reference to work

    if(i==0) return sum+=1 ; 
    fun1(i-1,x ,  n , sum) ; 
    if(i<n){
        if(i == 1) return sum+=x ; 
        else return sum+=pow(x,i); 
    }
    return sum ; 
}


//alternative 
//the recursive formula for this : f(x, n) = x^n + f(x, n-1)
//forward Recursion
int fun2(int x , int n , int i ){

    if(n==0) return 1 ; 
    if(i < n ) return pow(x, i) + fun2(x , n , i+1) ;
    return 0 ; 

}




int32_t main(){

    int x , n ; cin>>x>>n ;
    int sum = 0 ;  
    cout<<fun1(n , x , n , sum ) ; 
    //to use the alternative function1
    //cout<<fun2(x , n , 0) ;
 
}