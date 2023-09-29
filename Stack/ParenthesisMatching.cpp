//implementation: using array;
//for in depth understanding of the implementation , see "stackUsingarray.cpp" and "stack.md" file
#include<iostream>
using namespace std; 

class stack{
    //data
    int maxSize; 
    int top ; 
    char *array;

    //operations 
    public:
    stack(){
        top = -1; 
    }
    stack(int size){
        maxSize = size ; 
        top = -1; 
        array = new char[size] ; 
    }
    bool isEmpty(){
        if(top == -1) return true; 
        return false ; 
    }
    bool isFull(){
        if(top == maxSize-1)return true; 
        return false ;
    }
    void push(char x){
        if(isFull()) cout<<"Stack Overflow\n" ; 
        else array[++top] = x ; 
    }
    void pop(){
        if(isEmpty()) cout<<"Stack Underflow\n" ; 
        else top-- ;
    }
    char stackTop(){
        if(top == -1) return -1; 
        else return array[top] ; 
    }
    void display(){
        for(int i = 0; i<=top; i++){
            cout<<array[i]<<" " ;
        }
        cout<<"\n" ; 
    }
};

bool isBalanced(stack &stk , string &s){


    for(int i = 0 ; s[i] != '\0'; i++ ){
        if(s[i] == '(' || s[i] =='{' || s[i] =='[') stk.push(s[i]) ; 
        else if(s[i] == ')' || s[i] =='}' || s[i] ==']') {
            if(s[i] - stk.stackTop() == 1 || s[i] - stk.stackTop() == 2) stk.pop();
            //this  two lines can also be written as
            /*
            if(s[i] == ')' && top() == '(' || 
                s[i] == ']' && top() == '[' || 
                s[i] == '}' && top() == '{' ) stk.pop() ;*/
    }
    
    }
    if(stk.isEmpty()) {return true; }
    else {return false ;}
}
int main(){

    cout<<"Enter the maximum size of the array: ";
    int n ; cin>>n ; 
    stack stk(n) ;
    cout<<"Enter the string: ";
    string s; cin>>s;
    if(isBalanced(stk , s)){
        cout<<"Balanced\n"; 
    } 
    else cout<<"NotBalanced\n" ; 
    return 0 ; 


    
}
