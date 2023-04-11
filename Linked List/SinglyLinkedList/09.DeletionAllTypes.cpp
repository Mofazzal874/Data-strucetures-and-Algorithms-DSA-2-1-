#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

class node{
    public:
    int info ;
    node* next ; 
    
    node(int val){
        info = val ; 
        next = NULL ; 
    }
} ;

void lastInsert(node* &head , int data){

    node* n = new node(data) ;
    node* temp = head ;

    if( head == NULL){
        head = n ; 
        return ; 
    } 
    while(temp->next != NULL){
        temp = temp->next ;
    }
    temp->next = n ; 
}

void display(node* &head){
    
    node* temp = head; 
    while(temp != NULL){
        cout<<temp->info<<" ";
        temp = temp->next ; 
    }
    cout<<"\n" ; 

}


void  firstDelete(node* &head){

    node* toDel = head ; 
    head = head->next ; 
    delete toDel ;

}

void deletion(node* &head , int val){  //delete a linked list node with given value


    node* temp = head;

    if( head == NULL){                              //Corner Case-01
        cout<<"No node in the linked List\n" ; 
        return ; 
    }

    if(head->next == NULL){                         //corner case-02
        firstDelete(head) ; 
        return ; 
    } 

    while(temp->next->info != val){
        temp = temp->next ; 
    }

    node* toDel = temp->next ; 
    temp->next = temp->next->next ; 

    delete toDel ;

}

void lastDelete(node* &head){

    if(head == NULL){                               //Corner Case-01
        cout<<"No node in the linked List\n" ; 
        return ; 
    }

    if(head->next == NULL){                         //corner case-02
        firstDelete(head) ; 
        return ; 
    } 
    node* temp = head; 
    while(temp->next->next != NULL){
        temp = temp->next ; 
    }
    node* toDel = temp->next->next ; 
    temp->next = NULL ;
}

void deleteAfter(node* &head , int search){



    if(head == NULL){                               //Corner Case-01
        cout<<"No node in the linked List\n" ; 
        return ; 
    }

    if(head->next == NULL){                         //corner case-02
        cout<<"you must input two node to delete after a given value\n" ; 
        return ; 
    }

    node* temp  = head; 
    while(temp != NULL){
        if(temp->info == search){
            node* toDel = temp->next ; 
            temp->next = temp->next->next ; 
            delete toDel;
            return ; 
        }
        temp = temp->next ; 
    }
    
}
//another method of deleter after a given data (using two pointer )

void delAfter(node* &head , int search){

    node* temp = head ;
    node* forward ; //the node which will be deleted 
    
    while(temp->next != NULL){
        if(temp->info == search){
            forward = temp->next ; 
            temp->next = forward->next ; 
            delete forward ; 
            return ;  

        }
        temp = temp->next ; 
    }
}




void deleteBefore(node* &head , int search){

}

int main(){

   
    node* head = NULL ; 
    //node* temp =  NULL ; 
    int n ; cin>>n; 
    while(n--){
        int a ;cin>>a; 
        lastInsert(head , a) ;
    }
    delAfter(head, 1) ; 
    display(head) ; 
    


    
}
