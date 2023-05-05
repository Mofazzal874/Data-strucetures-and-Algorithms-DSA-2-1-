//what is tail recursion ?
//when the recursive call is the last statement in the function then it is called tail recursion
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
void fun(int n){
    if(n > 0){
        cout<<n<<" ";
        fun(n-1);
    }
}
int main(){
    
    int x = 3;
    fun(x) ; 
    return 0 ; 

}