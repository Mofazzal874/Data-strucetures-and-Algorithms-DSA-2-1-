//exponent function using recursion
// m^n = (m*m*m*m*m*...*m n-1 times)*m
// pow(m,n) = pow(m, n-1)*m
// pow(m,0) = 1

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int exponent(int n , int m){

    if( m == 0 ) return 1 ; 
    return exponent(n , m-1)*n ;
}

//now see the optimized version of this function
//if power is even then we can do it in half of the required time taken by the above function
int exponentOptimized(int n , int m){
    if( m == 0 ) return 1 ; 
    if( m%2 == 0 ) return exponentOptimized(n*n , m/2) ; 
    return n*exponentOptimized(n*n , (m-1)/2) ; 
}
int main(){
    int n , m ; cin>>n>>m ; 
    cout<<exponent(n , m)<<endl ;
    cout<<exponentOptimized(n , m)<<endl ; 
    return 0 ;
    
}