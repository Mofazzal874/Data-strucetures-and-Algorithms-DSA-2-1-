/*// There are two methods for doing this 
// method-01
// 01.Find The length of the LL
//02.ceil(length/2) with be the middle node
// Time complexity: O(n+n/2)

// Method-02
// 01. Take two pointer named p and q . P will travesed through the LL by one node at a time while q will be traversed 
// two node at a time.So By the time q reaches the end of the LL , p will reach the middle of the LL  .So P will be
// the middle node
// Time Complexity:O(n)

*/

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

node* findMiddle(node* &head){
    node* p , *q ; 
    p = q = head ; 
    while(q && q->next){
       q=q->next->next ; 
       p = p->next ; 
    }
    return p ; 

}
int main(){
    int n ; cin>>n ; 
    node* head = NULL ; 
    for(int i  = 0 ; i < n; i++){
        int a; cin>>a; 
        lastInsert(head , a) ;
    }
    node* fm = findMiddle(head) ; 
    cout<<fm->info<<endl;

    
}