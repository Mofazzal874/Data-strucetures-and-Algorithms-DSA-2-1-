//q: what is Tree Recursion? explain with diagram.
//ans: when a function calls itself more than one time in its body
//then it is called Tree Recursion.
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
void fun(int n){
    //static int x = 0 ;
    if( n>0) {
        cout<<n<<" "; 
        fun(n-1) ; 
        fun(n-1) ;
    }
    
}
int main(){
    int a = 3 ;
    fun(a);
    //cout<<"hello"  ;
    return 0 ;  
}