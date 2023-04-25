// this code merge two sorted linked list and after merging , the output linked list will also be 
// sorted

// You can take an additional array for the merged Linked List or You can do it without having any
// additional Linked List
//We will use two pointers method here . We'll can it Third and last pointer which will merge two linked list



#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

class node{
    public:
    int info ;
    node* next ;
    node(int val){
        info = val ; 
        next = NULL; 
    }  

};
void lastInsert( node* &head , int data){  
                                        

    node* n = new node(data);
    if(head == NULL){   
        head =n ;       
        return ;  

    }
    node *temp = head; 

    while(temp->next !=NULL){
        temp = temp->next; 
    } 
    temp->next = n ; 

}

void display(node* head){
    node* temp = head ; 
    while(temp != NULL){
        cout<<temp->info<<" ";
        temp = temp->next; 
    }
    cout<<"\n" ;
}


node* merge(node* first , node *second){

    node* third ;//this the head of the merged linked list , we'll return this pointer as head of the merged LL
    node* last; //this will help to merge two LL. This keeps tracks of the last node after merging every element 

    //Below if-else block is the initial conditions to decide the first element of the LL.Here Third(means the head of the merged LL) and
    //last will point to the same node
     if(first->info < second->info){
            third=last=first ; 
            first= first->next ; 
            third->next = NULL; 
    }
    else{
            third=last=second;
            second=second->next ; 
            third->next = NULL;  
    }
    //Now comes the loop part
    while(first && second) {  //if any of the two LL becomes NULL , the loop will stop 

        if(first->info < second->info){
            last->next = first ; //Linking  
            last = first ;         //shifting the last pointer to the merged positino
            first = first->next ; //moving first
            last->next = NULL ; 
        }
        //do the same if element in second is smaller than the first one
        else {
            last->next = second ; 
            last = second ; 
            second = second->next ; 
            last->next = NULL; 
        }

    }
    //Now if any element remain in first LL .......
    if(first) last->next = first ; //first!=NULL means some elements in the first LL still need merging 

    if(second) last->next = second ;  //otherwise do this 


    return third ; //returning the head of the merged LL

}
int main(){

    node* first = NULL  ; 
    node* second = NULL; 
    int m , n ;
    cout<<"Enter the Elements Number in each LL: " ;
    cin>>m>>n ; 
    cout<<"Enter elements of LL1: " ;
    for(int i = 0 ; i < m ; i++){
        int a; cin>>a; 
        lastInsert(first , a) ; 
    }
    cout<<"\nEnter elements of LL2: " ; 
    for(int i = 0 ; i < n ; i++){
        int a; cin>>a; 
        lastInsert(second, a) ; 
    }
    node* mergedLL = merge(first , second) ;
    cout<<"Merged Sorted Linked List: " ;
     
    display(mergedLL) ;    
}