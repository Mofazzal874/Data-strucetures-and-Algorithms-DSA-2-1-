//linked list insertion/lastInsertion
//this Implementation take O(n) 
//apna college

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
class node{
    public:
    int info ; 
    node* link; 

    node(int val){
        info = val ; 
        link = NULL;
    }
} ;

void lastInsert( node* &head , int data){  // why node* &head ??because we are using the
                                        // address of head in temp to traverse.Head is keeping the address of first node
                                        //and taking the pointer of Head (like node* &head) will make it possible to change 
                                        //it in temp ..see note khata for explanation/
                                        //example:
                                        //void fun(int &a){
                                        //a = 5;} erokom korle to a er value change kora zay 
                                        

    node* n = new node(data);
    if(head == NULL){   //if there is no node  .Means you're inserting first value
        head =n ;       //you'll make the n node as first node ,nothing else 
        return ;  

    }
    node *temp = head; 

    while(temp->link !=NULL){
        temp = temp->link; 
    } 
    temp->link = n ; 

}

void display(node* head){
    node* temp = head ; 
    while(temp != NULL){
        cout<<temp->info<<" ";
        temp = temp->link; 
    }
    cout<<"\n" ;
}
int main(){
    int n ; cin>>n ; 
    node* head = NULL ; 
    for(int i  = 0 ; i < n; i++){
        int a; cin>>a; 
        lastInsert(head , a) ;
    }
    display(head) ;
    return 0 ; 
    
}
