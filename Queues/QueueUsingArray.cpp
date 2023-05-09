#include<iostream>
using namespace std;
typedef long long ll;
//This implementation is done with Two pointer and using array
//front will always point before the first element and 
//rear will always point to the last element of the array \
//this two operation(enqueue and dequeue) will take (1) time
class queue{
    //data 
    int front;
    int rear;
    int maxSize ; 
    int* array ;
    //operations 
    public:
    queue(){
        front = rear = -1; 
    }
    queue(int s){
        front = rear = -1 ; 
        maxSize = s ; 
        array  = new int[maxSize]; 
    }

    void enqueue(int x) ; 
    int dequeue () ; 
    void display() ; 
    bool isEmpty() ; 
    bool isFull()  ; 
};
bool queue::isEmpty(){
    return front== rear ;
}

bool queue::isFull(){
    return rear == maxSize-1 ; 
}
void queue:: enqueue(int x){
    if(isFull()) cout<<"Queue is full\n" ; 
    else {
        rear++ ; 
        array[rear] = x ; 
    }
}
int queue::dequeue(){
    int x = -1; 
    if(isEmpty()) cout<<"Queue is empty\n" ; 
    else {
        x = array[front+1] ;
        front++ ;    
    }
    return x ; 
}
void queue:: display(){
    for(int i = front+1 ; i<=rear ;i++){
        cout<<array[i]<<" ";
    }
    cout<<endl;
}
int main(){
    cout<<"Enter the maxSize of the queue: " ; 
    int s ; cin>>s ; 
    queue q(s) ; 
    cout<<"Enter elements in the queue: ";
    for(int i = 0 ; i<s ; i++){
        int x ; cin>>x ; 
        q.enqueue(x) ; 
    }
    //q.enqueue(10) ;
    q.display();
    cout<<q.dequeue()<<endl;
    cout<<q.dequeue()<<endl; 
    return 0 ; 
    
}