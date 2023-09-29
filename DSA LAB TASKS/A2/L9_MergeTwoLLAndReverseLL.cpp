//problem : 
// Merge two linked List called L1 = 2,3,4 and L2 = 5, 6,7, 8 

// merged linked list = 2 , 5 , 3, 6 , 4 , 7, 8 

// Do it without using any extra node/link ; 



//this implementation uses doubly linked list 
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
class node{
    public:
    int data; 
    node* prev ; 
    node* next; 
    node(int val){
        data = val; 
        prev = NULL; 
        next = NULL ; 
    }
} ;

void create(node* head , int val){

    node* n = new node(val) ; 
    if(head == NULL) {
        head = n ; 
        return ; 
    }
    node* temp = head; 
    while(temp->next){
        temp = temp->next ; 
    }
    temp->next = n ; 
    n->prev = temp ; 
}


void display(node* &head){

    node* temp = head; 
    while(temp){
        cout<<temp->data<<" "; 
        temp = temp->next; 
    }
    cout<<"\n" ; 
}

void merge(node* &head1 , node* &head2){

    //as we are merging these two LL , if we lose out head pointer if won't create any problem .Because
    // we only need the new LL

    while(head1->next || head2->next){ //if any of these is null , get out 
            

    }

} 
int main(){
    
}