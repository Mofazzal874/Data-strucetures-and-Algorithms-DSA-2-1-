//Taylor series
//Taylor series using recursion
//e^x = 1 + x/1 + x^2/2! + x^3/3! + x^4/4! + ... + x^n/n!

// taylor series for optimization
//e^x = 1 + x/1(1 + x/2(1 + x/3(1 + x/4(1 + ... + x/n(1)))))


#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

double e(int x,int n){
    static double p = 1 , f = 1 ; 
    double r ; 
    if(n==0){
        return 1 ; 
    }
    else{
        r = e(x , n-1) ; 
        p = p*x ; 
        f = f*n ; 
        return r + p/f ; 
    }

}
// taylor series for optimization
//with horner's rule
double e2(int x , int n){
    static double s ; 
    if(n==0){
        return s ; 
    }
    else{
        s = 1 + x*s/n ; 
        return e2(x , n-1) ; 
    }
}

int main(){

    int x , n ; cin>>x>>n ; 
    cout<<e(x , n) ; 
    cout<<e2(x , n) ;


    
}