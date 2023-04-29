//for theory part , See"stack.md" file
#include<iostream>
using namespace std;
typedef long long ll;
class node{
    public:
    int data; 
    node* next ;
    node(){
        next = NULL;
    } 
    node(int val){
        data = val ; 
        next = NULL ;
    }
} ;


class stack{
    
    node* top ;   
public:
    stack(){ 
        top = NULL;  
    }
    bool isEmpty();
    void push(int val) ;
    int pop() ; 
    void display();


} ;
void stack::push(int val){
        node* n = new node(val) ; 
        if( n == NULL){
            cout<<"Stack OverFlow\n" ; //no more spaces in stack
        }
        else {
            n->next = top ; 
            top = n ; 
        }
}

bool stack::isEmpty(){
        if(top == NULL) return true; 
        return false; 
}

int stack::pop(){
    int x = -1 ; 
    if(isEmpty()) cout<<"Stack is Empty\n" ;
    else{
        x = top->data ; 
        node* toDel = top ; 
        top = top->next ; 
        delete toDel ; 
    }
    return x ; 

}

void stack:: display(){
        node* temp = top ; 
        while(temp){
            cout<<temp->data<<" ";
            temp= temp->next ;
        }
        cout<<"\n" ; 
    } 

int main(){
    stack stk ;
    stk.push(10) ; 
    stk.push(20) ; 
    stk.push(30) ; 
    stk.display() ; 
    cout<<stk.pop()<<"\n" ;
    stk.display() ;   
}


/*Terminal:
30 20 10 
30
20 10 
*/