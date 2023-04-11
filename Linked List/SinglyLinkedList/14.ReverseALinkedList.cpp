//______________________________________________________________Singly linked List_______________________________________________




// two methods to reverse 

// iterative method
// recursive method

// two ways to do it 
// rearrange the data in reverse order 
//reversing the nodes



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

                // way-01 : reversing the nodes :

//iterative method
                        

// we'll keep the data in their own position but we'll change the 
// address in reverse order
//if u take two pointers called current and previous , then you'll lose the next node of the linked list 
//so 
// we will need three pointers
// previous - initially NULL 
// current  - points head initially
// next - points the next of current node
// to make reverse , we'll just make the current pointer points to previous instead of next 
//if current becomes NULL ,that means you've reversed the list 
// head needs to be pointing to the last node


node* reverseMethod1( node* &head){
//Time complexity = O(n)

    node* prev = NULL ; 
    node* current = head ; 
    node* nextptr ;
    while(current != NULL){
        nextptr = current->next ;
        current->next = prev ;
        prev = current ; 
        current = nextptr ; 
    } 
    return prev ; //this is the new head of the reverse linked list 
}


//Recursive Method 



//we'll do the same thing , but in a recursive way 
//for example: we'll just make  the  function for first node and call the function recursively in that function 
//finally we'll make the next of first node to NULL , 
//and last node to new head 

node* reverseMethod2(node* head){
//Time complexity: O(n)


    if(head == NULL || head->next == NULL ){   //if ( no node/(linked list is empty) || last one node)
        return head; 
    }
    node* newhead = reverseMethod2(head->next) ;  // reverse will be done with this one line only.and for every call , below three lines will be executed for every return 
                                             //firstly , the last node will be reached        //
    //this three lines will be executed after every recursion call is complete 
    head->next->next = head; // 2 ta node reverse hocche
    head->next = NULL ;  //first node ke null e point kore dilam 

    return newhead; //this is the last node of the original linked list

}



            //way-02: reversing the elements
//reversing node is more preferable than reversing elements
//because it needs extra space for the additional array

/*
procedure:
01.take an array with the size of the linked list
02. copy all elements from the LL to the array
03.bring the pointer to the first node and start copying 
from the array reversely 
*/

void reverseMethod3(node* &head){
// TC: O(2*n) or O(n)

    vector<int> v; 
    node* temp = head; 
    while(temp){
        v.push_back(temp->info) ;
        temp= temp->next ;  
    }
    //bring the pointer to the first node 
    temp = head; 
    int l = v.size() - 1 ; 
    while(temp){
        temp->info = v[l] ; 
        l-- ; 
        temp = temp->next ; 
    }
}

int main(){
    int n ; cin>>n ; 
    node* head = NULL ; 
    for(int i  = 0 ; i < n; i++){
        int a; cin>>a; 
        lastInsert(head , a) ;
    }
    display(head) ;

    reverseMethod3(head) ; 
    display(head) ; 
    /*node* newHead = reverseMethod1(head) ; 
    display(newHead) ;
    cout<<"Reverse in a recursive way :\n " ;
    node* recursiveHead = reverseMethod2(newHead) ; 
    display(recursiveHead) ;*/ 
    
}