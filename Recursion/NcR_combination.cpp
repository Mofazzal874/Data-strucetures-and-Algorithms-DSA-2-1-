#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int fact(int n){
    if(n == 0) return 1; 
    return fact(n-1)*n;
}
//general function
int nCr(int n , int r){
    int num , denum ; 
    num =fact(n) ;
    denum = fact(r)*fact(n-r) ;

    return num/denum ;
}
//Optimized code of combination using pascals triangle

// pascals triangle
//see pascals triangle for better understanding
//from pascals triangle we can see that,
//nCr = (n-1)C(r-1) + (n-1)C(r)

int NCR(int N , int R){
    if(N ==  R || R == 0) return 1; 
    return NCR(N-1 , R-1)+NCR(N-1 , R) ;
}


int main(){

    int n , r ; cin>>n>>r ; 
    cout<<nCr(n , r)<<endl;
    cout<<endl;
    cout<<NCR(n , r)<<endl;
    
}