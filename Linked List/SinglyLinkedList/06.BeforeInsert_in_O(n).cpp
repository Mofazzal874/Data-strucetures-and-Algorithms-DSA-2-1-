#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
class node{
    public:
    int info ; 
    node* link  ;

    node(int val){
        info = val; 
        link = NULL ;
    }
} ;

//note: to see the two pointer method of beforeInsert , see -LinkedList_InsertingInASortedListInSortedPosition.cpp file
void beforeInsert(node* &head , int data , int search){

    node* n = new node(data) ;
    node* temp = head ; 
    if(temp->info == search){   //if the search data is in the first node ,then you have to firstInsert()
        n->link = temp ; 
        head = n ; 
        return ; 
    }
    while(temp!= NULL){
        if(temp->link->info == search){ //if u do this in this way ,  u dont have to take 
                                        //another temporary pointer to store the previous 
                                        //link , because youre already traversing a way before
                                        
                n->link = temp->link ;//think 
                temp->link = n ; 
                return ; 
        }
        else {
            temp = temp->link ;//increamenting  
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

    while(temp->link !=NULL){
        temp = temp->link; 
    } 
    temp->link = n ; 

}

void display(node* head){
    node* temp = head ; 
    while(temp != NULL){
        cout<<temp->info<<" ";
        temp = temp->link; 
    }
    cout<<"\n" ;
}
int main(){

    node* head = NULL ; 
    int n ;cin>>n; 
    while(n--){
        int a; cin>>a; 
        lastInsert(head , a) ;
    }
    beforeInsert(head , 2 , 1) ;
    beforeInsert(head, 6 , 5) ;
    beforeInsert(head , 4 , 3 ) ;
    beforeInsert(head , 4 , 3) ;
    beforeInsert(head , 3 , 3) ; 
    display(head) ;
}
