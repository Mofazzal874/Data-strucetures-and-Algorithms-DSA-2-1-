//what is Indirect Recursion?
//when a function is called by another function and that function calls 
//the first function again and this process goes on and on
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
void funB(int n) ;
void funA(int n){
    if( n>0) {
        cout<<n<<" "; 
        funB(n-1) ;
    }
    
}

void funB(int n){
    if( n>1) {
        cout<<n<<" "; 
        funA(n/2) ;
    }
}
int main(){
    int x = 3; 
    funA(3) ; 
    return 0 ; 
}