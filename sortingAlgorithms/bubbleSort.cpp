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

void bubbleSort(int a[] , int n){

    for( int i = 1 ; i <= n-1 ; i++){
        for(int j = 0 ; j <=(n-i) ;j++ ){
            if(a[j] > a[j+1]){
                swp(a[j] , a[j+1]) ; 
            }
        }
    }
}
/*
//optimised code for best time complexity :O(n)
//this is sometimes asked in interview
lets imagine a case , where the array is already sorted 
like this ; 2 3 5 7 10 
then u don't have to run all the round 

or this case : 4 3 2 5 7 10 
where 4 3 2 is not sorted and after that the array is sorted , so you don't need to swap after that; 
so you can check if all the swap cases in a round does happens or not . 
if not , then break the loop and take decision that the array is sorted 
otherwise simply go by the previous rule 
*/

void bubbleSortOptimised(int a[] , int n ) {
    for( int i = 1 ; i <= n-1 ; i++){
        int didswap = 0 ; 
        for(int j = 0 ; j <=(n-i) ;j++ ){
            if(a[j] > a[j+1]){
                swp(a[j] , a[j+1]) ;
                didswap = 1;  
            }
        }
        if( didswap == 0){ //this means no swap has happened .after this round , the array is sorted 
            break; 
        }
        cout<<"round: "<<i<<endl; //this will keep track if any round if passed or not 
    }

}


int main()
{
    int n ;cin>>n; 
    int array[n] ; 
    for(int i = 0 ; i < n ; i++){
        cin>>array[i] ;
    }
    bubbleSortOptimised(array , n) ;
    for(int i = 0 ; i < n ; i++){
        cout<<array[i]<<" " ;
    }
    


 
}