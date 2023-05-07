#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
static int x = 0 ;
void TOH(int n , int A , int B , int C){
    if(n > 0){
        TOH(n-1 , A , C , B) ;
        x++ ; 
        cout<<"("<<A<<","<<C<<")"<<endl ;
        TOH(n-1 , B , A , C) ;
    }
}
int main(){
    cout<<"Tower of Hanoi"<<endl ;
    cout<<"Moves: "<<endl ;
    TOH(4, 1 , 2 , 3) ;
    cout<<"Total moves: "<<x<<endl ;

}