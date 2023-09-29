#include<bits/stdc++.h>
using namespace std; 
typedef long long ll ;
int fun(int n){
    if( n > 0 ){
        return fun(n-1) + n ; 
    }
    return 0 ;
}


int main()
{   
    int n ; cin>>n ;
    cout<<"Sum of N natural numbers is: "<<fun(n)<<endl ;
    
}