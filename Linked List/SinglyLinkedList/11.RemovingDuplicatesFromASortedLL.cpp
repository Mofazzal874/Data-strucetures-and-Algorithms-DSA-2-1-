// remove duplicate elements in a sorted LL so that only distinct elements remain

// procedure:
// 01.take two pointers 
//02.check if two consecutive elements in the LL are same or not
// if they are same then delete the first occurance and connect the prev and next node
//else just traverse forward

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

class node{
    public:
    int data ;  
    node* next; 

    node(int val){
        data= val ; 
        next = NULL;
    }
} ;


void removeDup(node* &head){

    node* cur = head; 
    node* pre = NULL;  
    while(cur->next != NULL ){
        if( cur->data == cur->next->data){
            if( cur == head){
                node* toDel = cur; 
                cur = cur->next ;
                head = cur;  
                delete toDel; 

            }
            else{
                node* toDel = cur; 
                pre->next = cur->next ; 
                cur=cur->next ; 
                delete toDel;

            }
            
        }
        else{
            pre = cur ; 
            cur = cur->next ; 
        }
    }

}
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

    while(temp->next !=NULL){
        temp = temp->next; 
    } 
    temp->next = n ; 

}

void display(node* head){
    node* temp = head ; 
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next; 
    }
    cout<<"\n" ;
}

int main(){
    
    node* head = NULL ; 
    int n ; cin>>n; 
    while(n--){
        int a ; cin>>a; 
        lastInsert(head , a) ; 
    } 
    removeDup(head) ; 
    display(head) ;
//checked cases:
// 10
// 1 1 1 1 1 1 1 1 1 1
// 1  
//
// 10
// 1 1 1 2 3 4 4 4 5 10
// 1 2 3 4 5 10 
//
// 10
// 1 2 3 4 5 6 7 10 10 10
// 1 2 3 4 5 6 7 10
}

