//same program with time complexity O(1) 
//in this case we're taking a temporary pointer to store the current position after 
//inserting a node in the linked list 
//so *temp doesn't get vanished after the lastInsert() function get executed 
//in the previous code , *temp get vanished after the lastInsert() function executed 
//shakhawat sir implementation 

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

class node{
    public:
    int info ; 
    node* link ; 
    node(int val){
        info = val ; 
        link = NULL ;
    }
} ;

void lastInsert( node* &head , node* &temp , int data){
    node* n = new node(data) ;
    //temp = head ; 
    if(head == NULL){
        head = n; 
        temp = n ; 
        return ; 
    }
    else {
        temp->link = n;//storing the address of the present node in the (temp link) section of the previous node ;
        temp = n ; //changing the temp to the new pointer or //incrementing the temp pointer to the next 
    }
}

void display(node *head){
    node* tem = head; 
    while( tem != NULL){     //eikhane tem->link likhle kintu ekta element kom print hobe .last er new node tate link = NULL thakbe ..so oita print porjonto zawar agei
                                //loop stop hobe 
        cout<<tem->info<<" " ;//print kore nilam erpor,
        tem = tem->link ; //porer tate chole gelam 
    }
    cout<<"\n" ; 
}

int main(){
    int n ; cin>>n ; 
    node* head = NULL ; ///be cautious about this NULL in head while declaring it 
    node* temp = NULL ;
    for(int i  = 0 ; i < n; i++){
        int a; cin>>a; 
        lastInsert(head , temp ,  a) ;
    }
    display(head) ;
    return 0 ; 
    
}
