//this is program which illustrates the graph traversing technique -BFS





//code is not yet completed , 
// having problems with BFS

#include<bits/stdc++.h>

using namespace std;
typedef long long ll;


class node{
    public:
    int data; 
    node* next ; 
    
    node(int val){
        data = val ; 
        next = NULL ;
    }
};
class qu{
    node* front ; 
    node* rear ; 
    public: 
        qu(){
            front = rear = NULL; 
        }
    void push(int x){
        
        node* n = new node(x) ; 
        if(n == NULL) {
            cout<<"Heap is full\n" ; 
            return ;
        }
        else{
            if(front == NULL) {
                front = n ;
                rear = n ;
                return ; 
            } 
            else {
                rear->next = n ; 
                 rear = n ; 
            } 
        }
    }
    int pop(){

        int x = -1 ;

        if(front == NULL){
            cout<<"queue is Empty\n" ; 
        }
        else {
            x = front->data; 
        node * toDel = front ;
        front = front->next; 
        delete toDel;  

        }
        return x ; 
        
    }
    bool empty(){
        return front == NULL ; 
    }


} ;
 

void BFS(int mat[][8] , int start , int n){

    //int i = start , j; 
    qu  q; 
    int visited[8] = {0} ; 
    cout<<start<<" " ; 
    visited[start] = 1; 
    q.push(start) ; 
    while(!q.empty()){
        start = q.pop(); 
        for(int v = 1;v<n;v++ ){
            if(mat[start][v] == 1 && visited[v] == 0){
                cout<<v<<" " ; 
                visited[v] = 1; 
                q.push(v) ; 
            }
        }
    }
}

void DFS(int mat[][8] , int start , int n){
    
    static int visited[8] ={0} ; //taking it as static int array because recursion will happen .So the array should
                                //remember the state of its elements.Otherwise for like -"int visited[7]" declaration will cause to 
                                //redeclare the array everytime recursion happens

    if(visited[start] == 0){
        cout<<start<<" " ; 
        visited[start] = 1 ; 
        for(int v = 1; v<= n ; v++){
            if(mat[start][v] == 1 && visited[v] == 0){
                DFS(mat , v , n ) ;
            }
        }
    }

}
int main(){

    int A[8][8] ; 
    cout<<"Enter the graph as adjacency Matrix:\n\n" ; 
    for(int i = 0 ;i< 8; i++){
        for(int j = 0 ; j < 8 ; j++){
            cin>>A[i][j] ; 
        }
    }
    cout<<"BFS: \n" ; 
    BFS(A,3, 8) ;
    cout<<endl;

    cout<<"DFS: \n" ; 
    DFS(A,3,8) ; 
    cout<<endl;
    
}


//terminal:
// Enter the graph as adjacency Matrix:
// 0 0 0 0 0 0 0 0
// 0 0 1 1 1 0 0 0
// 0 1 0 1 0 0 0 0
// 0 1 1 0 1 1 0 0
// 0 1 0 1 0 1 0 0
// 0 0 0 1 1 0 1 1
// 0 0 0 0 0 1 0 0
// 0 0 0 0 0 1 0 0
// BFS: 
// 3 1 2 4 5 6 7 
// DFS: 
// 3 1 2 4 5 6 7