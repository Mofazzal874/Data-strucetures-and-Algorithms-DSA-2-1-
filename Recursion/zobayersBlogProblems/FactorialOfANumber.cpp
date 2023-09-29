//factorial
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int fact(int n){
    if( n == 0 ) return 1 ; 
    return fact(n-1)*n ; 
}
int main(){
    cout<<"Enter a number: " ;
    int n ; cin>>n ;
    cout<<"Factorial of "<<n<<" is: "<<fact(n)<<endl ;
    
}