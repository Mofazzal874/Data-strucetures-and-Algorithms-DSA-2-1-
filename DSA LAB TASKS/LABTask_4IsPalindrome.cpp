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
    if(head == NULL){
        firstInsert(head,val) ; 
        return ; 
    }
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


int isPalindrome(node* &head){
 
 
 
    node *first = head ;
    node *last = head ;
    while(last->next != NULL){
        last = last->next ;
    }
    while(first->next != NULL){
        if(last->info != first->info){
            return 0 ;
        }
        first = first->next ;
        last = last->prev ;
    }
    return 1;
 
}
int main(){
 
    node *head = NULL ;
    int n;cin>>n;
    //firstInsert(head , 1 ) ;
    //lastInsert(head , 2) ;
    //firstInsert(head , 4) ;
    //lastInsert(head , 2) ;
    //beforeInsert(head , 5 , 4) ;
    for(int i = 0 ; i < n ; i++){
        int a ; cin>>a;
        lastInsert(head , a) ;
    }
    firstInsert(head , 1 ) ;
    firstInsert(head , 1 ) ;
    display(head) ;
    cout<<endl;
    if(isPalindrome(head) == 1){
        cout<<"Palindrome"<<endl;
    }
    else if (isPalindrome(head) == 0){
        cout<<"Not palindrome"<<endl;
    }
 
 
}
 
 
