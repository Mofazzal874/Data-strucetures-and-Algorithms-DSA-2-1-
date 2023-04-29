#          **STACK**


stack use-

### LIFO- last in first out technique

---

* Now we well know that Recursion uses stack . Every time a Recursive function or recursion function happens in 
a program , a stack will automatically be provided for the program by the system .This is called system stack.
In this process, the programmer doesn't have to do anything.This is automatic , so compile time or runtime will
 take care of it.

 * But in iterative function(function using loop) or if we want to convert a recursive function to a iterative 
 function(every recursive function can be converted into iterative function),then we have to provide a stack 
 for the process.This stack should be created by the programmer. This is called programmers stack. 

* But not every recursion to iteration function conversion required stack. When should we use recursion is another
topic of discussion. 

---
--- 
## ADT of stack


ADT- abstract datatype of stack


ADT of stack will contain__

* Data representation of stack

* Operations of stack


 ### 01.Data:

* space for storing elements
* top pointer

### 02.Operations:

* Push(x)
* pop()
* peek(index)
* stackTop()
* isEmpty()
* isFull()
---
## Stack Implementation
* using array
* using Linked List
---
## **Stack Implementation using Array**
To implement stack using array(with the concept of ADT which is discussed in stack.md file) , we'll need the 
data representation of stack and operation of stack 

### for data representation of stack we'll need:
* Maximum size of the stack
* An array
* Top pointer

we'll make a class with these three things and operations of the stack to make everything abstract.

## important things :::

* Maximum size of the stack:we'll define the maximum size of the stack dynamically .That means we won't fix the size 
of the array.We'll take input from the user and define the max size in the runtime.

* An Array: As we are not fixing the size of the array in the program , we can't take an array like array[n] . We have to
 take a array pointer like int* array . Because we'll fix the size of the array dynamically.

 * Top pointer:After making the array , as no element will be there, so we'll make the top pointer to point to -1.


## **Stack Implementation Using Linked List:**

There's a difference while implementing using LL. 

* In array , Push and pop required less time while it is done in the right hand side of the array(it takes O(1) time) .



| 1 | 2 | 3 | 5 |...|
|---|---|---|---|---|
                O(1)
right most side will take O(1) time for array.


*But in Linked List , to push and pop in the right hand side will take O(n) time . Because every time you have to iterate to the last element . 
So push and pop in the start of the LL is time efficient.

| 1 | 2 | 3 | 5 |...|
|---|---|---|---|---|
                O(n)

so We will add or delete a node in the start of the linked List.

### Operations:
Maximum size of the stack:In Linked List you can add as many node as you want until the heap is full.

---
* isEmpty Condition: if the top pointer is NULL , that means no node is created and the stack is empty.
~~~
if(top == NULL) {
    empty;
}
~~~
---
---
* isFull condition: If you can not add any new node , that means the heap is full . So this is the isFull condition.

~~~ node *t = new node;

if(t == NULL){

    Full;
}
~~~
---


