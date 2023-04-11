/*Idea: pushes the maximum to the last by adjacent swapping
adjacent swapping is the keyword

(opposite of the selection sort . In selection sort we find minimum and swap it)
there will be many round of adjacent swapping 
In every round one maximum element will go to the last 

for example : 13 46 24 52 20 9 

procedure:
01.compare two adjacent element and swap them in order (e.g. for 13 46 , they will not swapped.
but 46 24 will get swapped and become 13 24 46 52 20 9  )
02.do it till the first maximum is on the last position of the array
03.repeat this process for every n - k th maximum 
like this 
1st round ; 
13 46 24 52 20 9 
13 24 46 52 20 9
13 24 46 52 20 9 
13 24 46 20 52 9
13 24 46 20 9 52 
here 52 is the first maximum in the array , and this will get to the last in first round . 
like this -- every 2nd , 3rd , 4th maximum in the array will get the last in every round. 

for 6 element , there will be 5 round( because the first element will get sorted automatically)
for n element , there will be n-1 round 
for 1st round , swap number - 0 to n-1 = 5
for 2nd round , swap number - 0 to n-2 = 4 ; 
for 3rd round , swap number - 0 to n- 3 = 3 
......


*/
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
//method-01
//swapping the nodes 
node* swpnode(node* &n1 , node* &n2){
    node* temp = n2->next ; 
    n2->next = n1 ; 
    n1->next = temp  ; 
    return n2 ;   
}

void bubbleSort(node* head , int n ){
    node* temp ; 
    for( int i = 1 ;i<= n - 1 ; i++){
        int didswap = 0 ; 
        temp = head; 
        for(int j = 0 ; j <= (n - i) ; j++){
            node* p1 = temp ; 
            node* p2 = p1->next ; 
            if(p1 ->info < p2->info){
                temp = swpnode(p1 ,p2) ; 
                didswap = 1; 

            }
            temp = temp->next; 

        }
        if(didswap == 0){
            break; 
        }
        cout<<"round: "<<i<<endl;
    }
    
}



int main()
{
    int n ;cin >> n ;
    node* head = NULL ; 
    for(int i = 0 ; i < n ; i++) {
       int a;  cin >> a ;
       lastInsert(head , a) ; 
    }
    bubbleSort(head , n ) ;
    display(head) ;
 
}