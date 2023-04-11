// this code insert a new element in a sorted position in a sorted linked list 
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

class node{
    public:
    int info ; 
    node* link; 

    node(int val){
        info = val ; 
        link = NULL;
    }
} ;

// there is two methods for this - 01.Single pointer method 
                                //    02.two pointers method
// 01.single pointer method
//this is same as beforeInsert.Difference is - the linked list is now sorted 
//this is single pointer Method
//you'll need total two pointers for this 
//time complexity - minimum o(1) and maximum - O(n) for every insertion 
void insertInsortedPos1(node* &head , int val){

    node* n = new node(val) ;                                                                                               //O(1)
    node* temp = head ; 
    if(temp->info >= val){   //if the search data is in the first node ,then you have to firstInsert()                      //O(1)
        n->link = temp ; 
        head = n ; 
        return ; 
    }
    while(temp!= NULL){                                                                                                 //O(n)
        if(temp->link->info >= val){ //if u do this in this way ,  u dont have to take 
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


//02.two pointer method
// you'll need total of three pointers for this 
// time complexity -same as before 
void insertInsortedPos2(node* &head , int val){


    node* n = new node(val) ;
    node* forward = head ;    //will search the element 
    node* prev = NULL ;    //will keep the address of previous node of the desired node ,so that you can link ...like this__
                        //                   []( previous node q) -> []( new node t ) -> [] (node with data greather than val) 
    if(forward->info >=val){
        n->link = forward ; 
        head = n ; 
        return ;
    }    

    while( forward && forward->info < val ){   //only p means - as long as p is not equal null(p!= NULL is same as p in while condition)
        prev = forward ;    //eita p pointer er previous address rakhbe 
        forward = forward->link ;  //eita val khuje ber korbe 
    } 
    //linking the new node with the previous(q) and next(p) node
    n->link = forward; 
    prev->link = n ; 

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
    cout<,"change the function name for using two methods\n" 
    int n ;cin>>n; 
    while(n--){
        int a; cin>>a; 
        lastInsert(head , a) ;
    }
    insertInsortedPos2(head , 1) ;
    insertInsortedPos2(head , 5) ;
    insertInsortedPos2(head , 4) ;
    //insertInsortedPos(head , 6) ;
    display(head) ; 

    
}