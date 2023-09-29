/*
If you already solved the problem for finding the nth fibonacci number,
then you must have a clear vision on how the program flow works. So now,
in this problem, print the values of your fibonacci function in pre-order,
in-order and post-order traversal. For example, when n = 5, your program 
calls 3 and 4 from it, from the call of 3, your program calls 1 and 2 again....... 
here is the picture:
                 5
              /    \
            3       4
          /  \     /  \
        1    2    2    3
                     /  \
                    1    2
                
Input:
5
Output:
Inorder: 1 3 2 5 2 4 1 3 2
Preorder: 5 3 1 2 4 2 3 1 2
Postorder: 1 2 3 2 1 2 3 4 5
*/
#include<bits/stdc++.h>
using namespace std;
#define int long long
template<typename T>
using min_heap = priority_queue<T , vector<T> , greater<T>> ; //to make minHeap. min_heap<type> name
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);



void  preFib(int n ){

    if(n==1||n==2){cout<<n<<" " ; return ; }
    cout<<n<<" " ; 
    preFib(n-2) ; 
    preFib(n-1) ; 
   


}


void inFib(int n){

    if(n==1||n==2){cout<<n<<" " ; return ; }
    inFib(n-2) ; 
    cout<<n<<" " ; 
    inFib(n-1) ;
}

void postFib(int n ){

    if(n==1||n==2){
        cout<<n<<" ";
        return ; 
    }
    postFib(n-2) ; 
    postFib(n-1) ;
    cout<<n<<" "; 

}

int32_t main(){
    int n ; cin>>n ;


    cout<<"Inorder: " ;
    inFib(n) ; 
    cout<<endl; 


    cout<<"Preorder: " ; 
    preFib(n) ;
    cout<<endl; 


    cout<<"Postorder: " ; 
    postFib(n) ; 
    cout<<endl;
     

    
}