/*
Write a recursive solution to compute lcm of two integers. You must not use the formula lcm(a,b) = (a x b) / gcd(a,b); find lcm from scratch...
Input:
23 488
Output:
11224*/
#include<bits/stdc++.h>
using namespace std;
#define int long long
template<typename T>
using min_heap = priority_queue<T , vector<T> , greater<T>> ; //to make minHeap. min_heap<type> name
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);




//naive approach-keep multiplying the bigger number by its factors untill the result is divisible by the minimum number
//why the bigger number?Because the LCM will be always be bigger than or equal to the bigger number of the two
//if 5 7(a b) are the numbers than the LCM will always be greater than or equal to 7(b) . it can't be smaller than 7  
int lcm1(int a , int b , int i ){

    if(a*i % b == 0 ) return a*i ; 
    return lcm1(a, b , i+1) ; 
}


//Using GCD(euclid's Algo) -gcd(a,b)*lcm(a,b) = a*b ; 
//the main part of this code is to find the gcd 
int gcd(int a , int b){
    if(b==0||a==b) return a ; 
    return gcd(b , a%b) ; 
}

int lcm2(int a , int b){
    return (a*b)/gcd(a , b) ; 
}




//iterative approach
int lcm3(int a , int b){
    if(a==0 || b==0) return -1 ;//undefined 
    int ma = max(a,b) ;
    int mb = min(a,b) ;
    for(int i = 1 ;; i++){
        if((ma*i)%mb == 0) return ma*i ;  
    } 
}
int32_t main(){
    int a , b ; cin>>a>>b ; 
    cout<<lcm3(a,b)<<endl ; 
}