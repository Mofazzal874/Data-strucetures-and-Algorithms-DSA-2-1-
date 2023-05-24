//Using the same space circularly
//if the front and rear reaches the maxSize, It will circle back to the 0th index of the array.
//And we will not start from -1 now . We will start from 0th index from now on.
//we will keep the 0th index empty.we will not use this now.We will use when the rear reaches the end , then we
// will circle back and insert at 0th index and starting to push from there.
//But keep in mind that you can use rear = front logic now.At least one index will always remain empty. 
//And that is the previous index of front.
//You need mod operation to circle back again 

// rear = (rear +1) % size
// front = (front +1)% size
//to move rear and front circularly 
//So here , array is not circular , but front and rear is circular (or they are moving circularly through the array)
// Circular Queue implementation in C++

#include <iostream>

using namespace std;

class Queue {
   private:
  int* items;
  int  front, rear;
  int SIZE  ; 

   public:
  Queue(int size) {
    SIZE = size ;
    items = new int[SIZE];
    front = rear = 0 ; //initially both are at 0th index
  }
  
  // Adding an element
  void enQueue(int element) {
    if ((rear+1)%SIZE == front) {
      cout << "Queue is full\n";
    } 
    else {
      rear = (rear + 1) % SIZE;
      items[rear] = element;
    }
  }
  // Removing an element
  int deQueue() {
    
    int element = -1;
    if (front == rear) {
      cout << "Queue is empty" << endl;
    } 
    else {
        front = (front + 1) % SIZE;
        element = items[front];
      }
    return element;
    
  }

    void display() {
      // Function to display status of Circular Queue
      
        int i = front+1;
        do{
            cout << items[i] << " ";
            i = (i + 1) % SIZE; //circularly moving through the array
        }
        while(i != (rear+1)%SIZE);
        cout << endl;
    }
};

int main() {

    cout<<"Enter the size of the queue: " ; 
    int n ; cin>>n; 
    Queue q(5);


    q.enQueue(1);
    q.enQueue(2);
    q.enQueue(3);
    q.enQueue(4);
    q.enQueue(5);
    //the last element will not be inserted as the queue is full.becaue we will always keep one index empty
    //so that we can differentiate between empty and full queue
    q.display();
    q.deQueue();
    q.display();
    return 0;
}
