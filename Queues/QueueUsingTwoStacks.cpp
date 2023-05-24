// the main idea is - take 2 stacks , one is for loading(inserting) elements of the queue and other is for unloading(dequeue)elements from the queue 
// Here the 2nd stack will be taken to reverse the order of inserted element to make it look like an queue while dequeueing




//This implementation is not recomended , because this operation take much memory and time.

// Time complexity for-
// inserting- O(1)
// deletion- O(n) for each element
// display-o(n*n) for n elements
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
    node* stackTop(){
        if(top == NULL) return NULL ; 
        return top ;
    }


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
}

class Queue{

    stack s1, s2;
    public:
    void enQueue(int val){
        s1.push(val) ; 
    }
    int deQueue(){
        int x = -1; 
        if(s2.isEmpty()){
            if(s1.isEmpty()){
                cout<<"Queue is Empty\n" ; 
                return x ; 
            }
            else {
                while(!s1.isEmpty()){
                    s2.push(s1.pop()) ; 
                }
            }
        }
        x = s2.pop() ; 
        return x ; 
    }
     void Display() {
        cout<<"Queue is : " ;
        s2.display(); //first showing the content of s2 stack(if s2 is not empty) and if s2 is empty , then nothing will be printed simply.
        int counter = 0 ; //taking an counter to count how many element we are pushing into the 2nd stack , so that we can print the stack like a
                            //a queue
        //the below part does the work of counting the pushed element and returning them into their previous positiion(in stack s1), so that
        //we dont face any problem while doing the dequeue operation  
        while(!s1.isEmpty()){
            s2.push(s1.pop()) ; 
            counter++ ; 
        }
        while(counter--){
            int x = s2.pop(); 
            cout<<x<<" " ; 
            s1.push(x) ; 
            
        }
        cout<<"\n" ; 
    }
    
} ;

int main(){


    Queue q;
    cout<<"Enter the number of elements in the Queue: " ; 
    int n ; cin>>n ; 
    cout<<"Enter elements in the queue: ";
    for(int i = 0 ; i< n ; i++){
        int x ; cin>>x ; 
        q.enQueue(x) ; 
    }
    q.Display();
    q.enQueue(6) ; 
    q.enQueue(7) ; 
    q.Display() ; 
}
//terminal:
// Enter the number of elements in the Queue: 5
// Enter elements in the queue: 1 2 3 4 5
// Queue is : 1 2 3 4 5 
// Queue is : 1 2 3 4 5 6 7