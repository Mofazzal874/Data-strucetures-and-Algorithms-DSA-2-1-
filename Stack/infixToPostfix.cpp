#include<iostream>
#include<cstring>
using namespace std;
typedef long long ll;
template <class T>
class stack{
    int maxSize; 
    int top ; 
    T* array;
    public:
    stack(int n){
        maxSize = n;
        top = -1 ; 
        array = new T[n] ;  
    }
    bool isEmpty(){
        return (top <0) ;
    }
    /*
    THis isEmpty() function can also be written as ----
    bool isEmpty(){
        return top = -1;
    }*/
    bool isFull(){
        return (top == maxSize-1) ;  
    }
    void push(T val) {
    if(isFull()) cout<<"Stack Overflow\n" ;
    else{
        top++ ; 
        array[top] = val ;
    }
    }
    T pop(){
        T x = -1 ; 
        if(isEmpty()) {
            cout<<"Stack Underflow\n" ;
             
        }
        else{
            x = array[top] ;
            top-- ;
        }
        return x ;
    }
    T stackTop(){
        if(top == -1) return -1; 
        else return array[top] ; 
    }
    T peek(int pos){
        T x = -1; 
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
    

};
 
bool isOperand(char x){
    if(x =='+' || x == '-' || x == '*' || x == '/') return false; 
    return true; 
}

int precedence(char x){
    if(x == '+' || x == '-') return 1 ; 
    if(x == '*' || x == '/') return 2 ;
    if(x == '^') return 3; 
    else return 0; 
}

string inToPost(string infix){

    cout<<"Enter the maxSize of stack: " ; 
    int n ; cin>>n ; 
    stack <char> st(n);
    string postfix = "";
    int i =0; 
    while(infix[i] !='\0'){
        if(infix[i]>='a' && infix[i]<='z'|| infix[i]>='A'&& infix[i]<='Z') {
            postfix+=infix[i];
            i++;
        } 
        else if(infix[i] == '('){
            st.push(infix[i]);
            i++ ;
        }
        else if(infix[i] == ')'){
            while(st.stackTop() != '(') {
                postfix+=st.pop();
            }
            st.pop() ; 
            i++ ;         
        }
        else {
            while(!st.isEmpty() && precedence(infix[i]) <= precedence(st.stackTop())){
                postfix+=st.pop();
            }
            st.push(infix[i]);
            i++;
        }
        }
           //now something can also remain in the stack.Now we have to copy it in the postfix string 
        while(!st.isEmpty()){
            postfix +=st.pop() ;
        } 
        return postfix; 


    } 

int main(){

    cout<<"Enter the infix expression: " ; 
    string infix ; cin>>infix;
    cout<<"Postfix is :"<<inToPost(infix) ;
    return 0; 
}