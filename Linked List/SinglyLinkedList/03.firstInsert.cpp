#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

class node{
    public:
    int info ; 
    node* link ; 
    node(int val){
        info = val ; 
        link = NULL ;
    }
} ;

void lastInsert( node* &head , node* &temp , int data){
    node* n = new node(data) ;
    //temp = head ; 
    if(head == NULL){
        head = n; 
        temp = n ; 
        return ; 
    }
    else {
        temp->link = n; 
        temp = n ; 
    }
}
void firstInsert(node* &head , int data) 
{
  node *n = new node(data) ; 
  n->link = head;
  head = n ; 
   
}
void display(node *head){
    node* tem = head; 
    while( tem != NULL){
        cout<<tem->info<<" " ;
        tem = tem->link ; 
    }
    cout<<"\n" ; 
}

int main(){
    int n ; cin>>n ; 
    node* head = NULL ; ///be cautious about this NULL in head while declaring it 
    node* temp = NULL ;
    for(int i  = 0 ; i < n; i++){
        int a; cin>>a; 
        lastInsert(head , temp ,  a) ;
    }
    firstInsert(head , 6) ; 
    display(head) ;
    return 0 ; 
    
}
