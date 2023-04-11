/*Idea:
To remember : select minimum and swap them
source.Strivers 

lets say you have the following array : 13 46 24 52 20 9
procedure:
01.you have to find the minimum in the whole array and swap it with the first element .
now the array is like this -> 9 46 24 52 20 13 
02.now you have to select the minimum in 46 24 52 20 13 and swap it with 46 . 
03. this will goes on for 5 times . so 
for 6 elements you to swap 5 times . because the last elements remaining will be always sorted .*/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


class node{
    public:
    int info ;
    node* next ;
    node(int val){
        info = val ; 
        next = NULL; 
    }  

};



void lastInsert( node* &head , int data){  
                                        

    node* n = new node(data);
    if(head == NULL){   
        head =n ;       
        return ;  

    }
    node *temp = head; 

    while(temp->next !=NULL){
        temp = temp->next; 
    } 
    temp->next = n ; 

}

void display(node* head){
    node* temp = head ; 
    while(temp != NULL){
        cout<<temp->info<<" ";
        temp = temp->next; 
    }
    cout<<"\n" ;
}





void swp (int &a , int &b){

    a = a+b ; 
    b = a- b ;
    a = a - b ;  
}

void selectionSort(node* &head){

   node* temp1 = head ;
   while(temp1->next->next){
        node* min = temp1 ; 
        node* temp2 = temp1->next; 
        while(temp2){
            if(temp2->info < temp1->info){
                min = temp2 ; 
            }
            temp2 = temp2->next ; 
        }
        if( temp1 != min){
            swp(min->info , temp1->info)  ;
        }
        temp1 = temp1->next ;    
   } 

}
int main(){
    int n ;cin >> n ;
    node* head = NULL ; 
    for(int i = 0 ; i < n ; i++) {
       int a;  cin >> a ;
       lastInsert(head , a) ; 
    }
    selectionSort(head) ;
    display(head) ; 
    
}