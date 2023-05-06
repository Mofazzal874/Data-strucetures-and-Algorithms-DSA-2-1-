//what is nested Recursion?
//when a function is called by itself as a parameter then it is called nested recursion

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int fun(int n){
    if( n>100) return n-10 ; 
    else return fun(fun(n+11)) ; 
}

int main(){
    int a = 95 ;
    cout<<fun(a);
    return 0 ;  
}
