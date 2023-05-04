
# **Generalizing Recursion**
lets assume _fun1_ is a recursive function 
```
void fun1(int n ){

    if(n>0){
        ------calling ;
        fun1(n-1) ;
        if any constant number of function is multiplied/added/divided/subtracted with the recursive function ,they will be executed in the function returning time
        
        -----returning ;

        so ,  everything before the recursive function will be executed in function calling time
        and everything after the recursive function will be executed in function return time  
    }
    
}
```
for example:
```
void func1(int n){
    if(n>0){
        cout<<n<<" ";
        func1(n-1) ; 
    }
}

int main(){

    int  x = 3 ; 
    func1(3) ; 
}
this will print: 3 2 1

On the otherhand:
void func1(int n){
    if(n>0){
        
        func1(n-1) ;
        cout<<n<<" "; 
    }
}


---
this will print: 1 2 3
---
``` 

Because for the first function , we are printing in the function calling time and for the second function , we are printing
the number in function returning time ; 