// what is head recursion?
// when the recursive call is the first statement in the function then it is called head recursion

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int fun(int n){
    if( n>0) {return fun(n-1)+n;}
    return 0 ;
}
int main(){
    int a = 5;
    cout<<fun(a);
    return 0 ;  
}