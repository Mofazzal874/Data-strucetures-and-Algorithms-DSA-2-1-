//this program implements Double Ended Queue using circular array
// that means we can both insert and delete elements from both the ends of the queue
//we will use two pointer methods to implement this-front and rear .Front will insert and delete 
// from the front and rear will insert and delete from the rear
//rest of concept is same as circular queue

#include <iostream>
using namespace std;

class Queue{
    int* items ; 
    int front ; 
    int rear ; 
    int SIZE ;
    public:
    Queue(int size){
        SIZE = size ; 
        items = new int[SIZE] ; 
        front = rear =  0 ; 
    }
    void enQueue(int val){
        if((rear+1)%SIZE == front){
            cout<<"Queue is Full\n" ; 
            return ; 
        }
        else {
            rear = (rear+1)%SIZE ; 
            items[rear] = val ; 
        }
    }
    void enQueueAtFirst(int val) {
    if ((front - 1 + SIZE) % SIZE == rear) {//mod can generate negative value if you do (front -1)%Size .
                                            //so we are adding the Size with (front -1) to make the whole 
                                            //operation positive
        cout << "No space at front\n";
        return;
    } 
    else {
        items[front] = val; //dont put this line after the below(front = (front - 1 + SIZE) % SIZE ;)line , 
                            //beacuse if you do so , this function will not work properly....THINK.......
        front = (front - 1 + SIZE) % SIZE; 
    }
}

    int deQueueAtFirst(){
        int x = -1; 
        if(front == rear){cout<<"Queue is Empty\n" ;}
        else {
            front = (front+1)%SIZE ;
            x = items[front] ; 
        }
        return x ; 
    }
    void enQueueAtLast(int val){
        if((rear+1)%SIZE == front){
            cout<<"Queue is Full\n" ; 
            return ; 
        }
        else {
            rear = (rear+1)%SIZE ; 
            items[rear] = val ;
        }
    }
    int deQueueAtLast(){
        int x = -1; 
        if(front == rear){
            cout<<"Queue is Full\n" ; 
        }
        else{
            x = items[rear] ; 
            rear = (rear-1)%SIZE ; 
        }
        return x ;
    }
    void display() {
        //there can be two case for this 
        //case-01
        if(front < rear){
            int i = front+1 ; 
            while(i<= rear){
                cout<<items[i]<<" " ; 
                i++ ; 
            }
        }
        else { //front>= rear

            int i = front ; 
            while(i<=rear){
                cout<<items[i]<<" " ; 
                i = (i+1)%SIZE ; 
            }
        }
        cout<<endl;
    }
} ;

int main(){
    cout<<"Enter the size of the circular array: ";
    int n ; cin>>n; 
    Queue q(n) ;
    cout<<"Input Data: " ;  
    for(int i =0 ; i < n-1 ; i++){
        int a ; cin>>a; 
        q.enQueue(a) ; 
    }
    q.display() ; 
    cout<<q.deQueueAtFirst()<<endl;
    q.display() ;
    cout<<q.deQueueAtLast()<<endl;
    cout<<q.deQueueAtLast()<<endl;
    cout<<q.deQueueAtLast()<<endl;
    q.display() ; 
    q.enQueueAtFirst(20) ;
    q.display() ; 
    q.enQueueAtLast(7) ; 
    q.display() ; 
}
//terminal
// Enter the size of the circular array: 5
// Input Data: 1 2 3 4
// 1 2 3 4 
// 1
// 2 3 4 
// 4
// 3
// 2
// 1
// 20
// 20 7
