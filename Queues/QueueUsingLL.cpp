//this program implements a queue using linked list
//here we take two pointers to point to the front and rear of the queue
//we can also use one pointer(e.g. the head only) , but this implementation will take O(n) time for enQueue() operation
//so we use two pointers to point to the front and rear of the queue

#include <iostream>
using namespace std; 

class node{

    public:
    int data; 
    node* next ; 
    node(int val){
        data = val ; 
        next = NULL ;
    }

} ;

class Queue{

    node* front ; 
    node* rear ; 
    public:
    Queue(){
        front = NULL ; 
        rear = NULL ; 
    }
    void enQueue(int val){

        node* n = new node(val) ; 
        if( n == NULL) {
            cout<<"Queue is fuLL\n" ; //actually the heap is full here
            return ; 
        }
        else {
            if(front == NULL){
                front = n ; 
                rear = n;
                return ; 
                
            }
            rear->next = n ;
            rear = n ; 
        }
    }
    int deQueue(){
        int x= -1 ;
        if(front == NULL){
            cout<<"Queue is Empty\n" ; 
        }
        else {
            x = front->data; 
            node* toDel = front ; 
            front = front->next ;
            delete toDel;
        }
        return x ; 
    }
    void display(){
        node* temp = front ; 
        while(temp){
            cout<<temp->data<<" " ; 
            temp = temp->next; 
        }
        cout<<endl;
    }
};

int main(){
    Queue q ; 
    q.enQueue(10);
    q.enQueue(20);
    q.enQueue(30);
    q.enQueue(40);
    q.enQueue(50);
    q.display();
    printf("%d ",q.deQueue());
    return 0;
}
