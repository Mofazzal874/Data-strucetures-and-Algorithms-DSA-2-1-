//For theory part, go to stack.md file

//Time complexity of every operation in stack is constant O(1)
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
class stk{  //everything is discussed in stack.md file

    //data 
    int size; 
    int top ; 
    int* array;
    
    //operations 
    public:
    stk(){
        top = -1;
    }
    stk(int data){
        size = data; 
        top = -1 ; //initially pointing to -1 
        array = new int[data] ; //fixing the size of the array from the data of the user
    }
    
    bool isEmpty(){
        if(top == -1) return true; 
        return false ; 
    }
    bool isFull(){
        if(top == size-1) return true; 
        return false; 
    }
    void push( int x){
        if(!isFull()){
            top++ ; 
            array[top] = x ; 
        } 
        else cout<<"Stack Overflow\n" ;
    }
    int pop(){
        int x = -1 ; //taking a variable which will return the deleted value
                    //initializing it with -1
        if(!isEmpty()){
            x = array[top] ; 
            top--;
        } 
        else cout<<"stack Underflow\n" ;

        return x ; //if stack is empty , this will return -1 
                //else the deleted value will be returned
    }
    int peek(int pos){
        int x = -1; 
        if(top-pos+1 <0){
            cout<<"invalid position\n" ; 
        }
        else 
        {
            x = array[top-pos+1] ; 
            return x ;
        }
        return x ;   
    }

    int stkTop(){
        if(top==-1) return -1; 
        else return array[top] ;
    } 
    void display(){
        for(int i = 0 ; i <= top ; i++){
            cout<<array[i]<<" " ;
        }
        cout<<"\n" ; 
    } 
};

int main(){
    
    cout<<"Enter the Maximum size of the stack: " ; 
    int n ; cin>> n ; 
    stk st(n) ;
    cout<<"Enter the number of elements you want to push in the stack initially: " ;
    int p ; cin>>p ; 
    for(int i = 0 ; i < p ; i++){
        int a ; cin>>a; 
        st.push(a) ;
    } 
    cout<<"Visualization of Stack: " ;
    st.display() ;
    st.push(7) ; 
    st.display() ;
    st.push(7) ;
    st.display() ; 
    cout<<st.peek(5)<<"\n";
    cout<<st.isEmpty()<<"\n" ; 
    cout<<st.isFull()<<"\n" ;  
    cout<<st.pop()<<" " ;
    cout<<st.pop()<<" " ;
    cout<<st.pop()<<" " ;
    cout<<st.pop()<<" " ;
    cout<<st.pop()<<" " ;
    cout<<st.pop()<<" " ;
    cout<<st.pop()<<" " ;
    cout<<"\n" ; 
    cout<<st.isEmpty()<<"\n" ;
    st.push(1);
    st.push(1);
    st.push(1); 
    st.push(1);
    st.push(1);
    st.push(1);
    st.push(1);
    st.push(1);
    st.push(1);
    st.push(1);
    st.push(1) ;
    st.display() ;    
}
/*
:::TERMINAL::::::::::::::

Enter the Maximum size of the stack: 10
Enter the number of elements you want to push in the stack initially: 5
1 2 3 4 5
Visualization of Stack: 1 2 3 4 5 
1 2 3 4 5 7 
1 2 3 4 5 7 7 
3
0
0
7 7 5 4 3 2 1
1
Stack Overflow
1 1 1 1 1 1 1 1 1 1*/