#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

class node{
    public:
    int info ; 
    node* link;
    node(int val){
        info = val ; 
        link = NULL ;
    }
} ;
void deletion(node* &head , int delData){

        node* temp = head; 
        while(temp->link->info != delData){ //previous pointer a theme zabo
            temp = temp->link ;            //traversing till we get the previous node(n-1th) of 
                                        //delValue node. 
        }
        node* toDel =temp->link ; //to delete the nth address , we're pointing nth node .
        temp->link = temp->link->link ; //connecting the n-1th and the n+1 th node 
        delete toDel ; 
         

}

void lastInsert(node* &head , int data){
    
    node* n = new node(data) ;
    if(head == NULL){
        head = n ;  
        return ; 
    }
    node* temp = head; 
    while(temp->link != NULL){
        temp = temp->link;
    }
    temp->link = n ; 
} 

void display(node* head){
    node* tem = head; 
    while(tem != NULL){
        cout<<tem->info<<endl;
        tem = tem->link ; 
    }
}

int main(){

    node* head = NULL ; 
    //node* temp =  NULL ; 
    int n ; cin>>n; 
    while(n--){
        int a ;cin>>a; 
        lastInsert(head , a) ;
    }
    deletion(head , 3) ;
    display(head) ;
    
}
