#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

class node{
    public:
    int info ; 
    node* prev; 
    node* next ; 

    node(int val){
        info = val ; 
        prev = NULL; 
        next = NULL ;
    }

} ;




void firstInsert(node* &head, int val){

    node* n = new node(val)  ; 
    n->next = head ; 
    if(head != NULL){
        head->prev = n ; 
    }
    head = n ;
     

}

  
void firstDelete(node* &head , int val){

    node* toDel  = head ; 
    head = head->next ; 
    head->prev = NULL ; 
    delete toDel ; 
} 



void lastDelete(node* &head , int val){

    node* temp = head; 
    while(temp->next != NULL){
        temp = temp->next ; 
    }
    temp->prev->next = NULL ; 
    delete temp ; 

}
void  deletion(node* &head , int val){

   

    node* temp = head; 

    while(temp != NULL){
        

        if(temp->info == val){

            if(temp == head){
                firstDelete(head, val) ; 
                return ;
            }

            if(temp->next == NULL){
                lastDelete(head, val) ; 
                return ; 
            }
            
            temp->prev->next = temp->next ;
            temp->next->prev = temp->prev ; 
            delete temp ; 
            return ; 

        }
        temp = temp->next ;
    }
}


void lastInsert(node* &head, int val){



    if(head == NULL){
        firstInsert(head,val) ; 
        return ; 
    }

    node* n = new node(val) ; 
    node* temp = head ; 
   
    while(temp->next != NULL){
        temp = temp->next ;
    }
    temp->next = n ; 
    n->prev = temp ; 
}


void display(node* &head){

    node* temp = head ; 
    while(temp!=NULL){
        cout<<temp->info<<" " ;
        temp = temp->next ; 
    }
    cout<<"\n" ; 
}


int main(){

    node* head = NULL  ;
    int n ; cin>>n ; 
    while(n--){
        int a ; cin>>a; 
        lastInsert(head, a) ;
    } 
    display(head) ; 
    deletion(head, 3) ;
    display(head) ;
    deletion(head, 1) ; 
    display(head) ; 
    deletion(head, 5) ; 
    display(head) ; 
    firstInsert(head, 1) ; 
    firstInsert(head, 1) ; 
    firstInsert(head, 1) ; 
    firstInsert(head, 1) ; 
    display(head)  ;
    lastInsert(head, 4) ;
    lastInsert(head, 4) ; 
    lastInsert(head, 4) ; 
    lastInsert(head, 4) ; 
    display(head) ; 

    
}
