// This code checks if a linked list is sorted or not 
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

} ;

void lastInsert(node* &head ,int val ){

    node* n = new node(val) ; 
    if( head == NULL){
        head = n ; 
        return ;
    }
    node* temp = head; 
    while(temp->next != NULL){
        temp = temp->next ; 
    }
    temp->next = n ; 
}
void display(node* &head){
    node* temp = head; 
    while(temp != NULL){
        cout<<temp->data<<" " ;
        temp = temp->next ; 
    }
}

bool isSorted(node* &head){

    node* temp = head ; 
    int min = INT_MIN  ;

    while(temp != NULL){
        if( temp->data > min){
            min = temp->data ;
              
        }
        else return false ;
        temp = temp->next ; 
    }
    return true; 
}
int main(){
    
    int n ; cin>>n ;
    node* head = NULL ;  
    for( int i = 0 ; i < n ; i++){
        int a ; cin>>a; 
        lastInsert(head , a) ; 
    }
    if(isSorted(head)){
        cout<<"sorted" ;  
    }
    else {
        cout<<"Unsorted" ; 
    }
    return 0 ; 
    
}