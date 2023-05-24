# **QUEUES**
###Idea:FIFO(first in , first out)
both opening is used 

## **ADT Of queue**
* Data:
i.space for storing elements 

ii.front pointer - for deletion

iii.rear pointer - for insertion

* Operation:
  i.enqueue(x)-in rear end

  ii.dequeue()-from front end

  iii.isEmpty()

  iv.isFull()

  v.first()

  vi.last()

---

  *Implementation:
  i.array

  ii.linked List

---
## **QUEUEs USING array**

* queue using -single pointer
* queue using -front and rear pointer
* Drawbacks of Queue using Array
---
### Using single pointer

* drawbacks
insertion-O(1)
deletion - O(n)


### Using Two pointer

### **Drawbacks of Queue using Array**
*Cannot reused the deleted elements indexes>>>>
if the front pointer is not pointing to the oth index of the array and if the rear is pointing to the maxSize'th index of the array , then if we try to insert an element , the output will be - queue is Full.(Although there is space in the front side) .. so this is a problem which is solved by using resetting the two pointers to 0.

* Every position can be used only once.....

* A situation like isEmpty() and isFull() is created if you delete all the element in the queue , Then there is full also and empty also condition arrives

### **Solutions:**
* i.resetting pointers

->at anytime , anyplace , if the queue is becoming empty(front == rear) ,bring the front and rear pointer to -1.This way the space can be reused .

* ii.Circular Queue.
