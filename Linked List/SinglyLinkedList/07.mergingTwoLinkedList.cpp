#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
class node {
    public:
    int info ; 
    node *link ; 

} ;
void creation(node **head , int data){
    node *ptr = new node() ; 
    ptr->info = data; 
    ptr->link = NULL ; 
    if(*head == NULL){
        *(head) = ptr ; 
        return ; 
    }
    else {
        node *temp = *head; 
        while(temp->link != NULL){
            temp = temp->link; 
        }
        temp->link = ptr; 
        return ; 
    }
}

int firstInsert(node **head , int data , int n){
    node *ptr = new node() ; 
    ptr->info = data; 
    ptr->link = *head; 
    *head = ptr ; 
    return n+1 ; 
}
int lastInsert(node **head , int data , int n ){

     node *ptr = new node() ; 
    ptr->info = data; 
    ptr->link = NULL ; 
    if(*head == NULL){
        *(head) = ptr ; 
        return n+1; 
    }
    else {
        node *temp = *head; 
        while(temp->link != NULL){
            temp = temp->link; 
        }
        temp->link = ptr; 
        return n+1  ; 
    }

}
void display(node **head){
    node *temp = *head; 
    while(temp != NULL){
        cout<<temp->info<<" "  ;
        temp = temp->link ; 
    }
}
int merge(node **head1 , node **head2  , int n1 , int n2 ){
    node *temp = *head1 ; 
    while( temp->link != NULL){
        temp = temp->link ; 
    }
    temp->link = *head2 ; 
        return n1+n2 ; 

}
int main(){
    node *head1 = NULL ; 
    node *head2 = NULL ; 
    cout<<"Enter N for list 1:\n" ;
    int data ; 
    int n1 ; cin>>n1 ; 
    for( int i = 0 ; i < n1 ; i++){
        cin>>data; 
        creation(&head1 , data) ;
    }
    //display(&head1) ;
    cout<<"Enter N for list 2:\n" ;
    int n2 ; cin>>n2 ;
    for( int i = 0 ; i < n2 ; i++){
        cin>>data; 
        creation(&head2 , data) ;
    }
    //display(&head2) ; 
    merge(&head1 , &head2 , n1 , n2) ;
    cout<<"\n" ;
    display(&head1) ;

    
    
}
