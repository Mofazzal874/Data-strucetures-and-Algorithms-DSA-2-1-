#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

class node{
    public:
    int data;
    node* left ;
    node* right ; 
    node(){
        left = right = NULL ; 
    }
    node(int d){
        data = d;
        left = right = NULL;
    }
} ;

//takes O(logn) time
//takes O(n) in worst case scenario
node* insert(node* root , int data){

    if(root == NULL) //This means we have reached the leaf or last node or Desired node to insert a new node with value = data 
                    // Then simply just create the node and return 
    return new node(data);

    if(data < root->data) root->left =  insert(root->left,data);

    else if(data > root->data) root->right = insert(root->right,data);

    return root;//if to be inserted data is same as root->data value , then simply just return .
                // Don't have to do anything

     
}

int Height(node* p ){

    int x , y ;
    if(p == NULL ) return 0 ; 
    x = Height(p->left) ; 
    y = Height(p->right) ; 
    

    return x>y?(x+1):(y+1) ; 
}

node* inOrderPre(node* p ){

    while(p && p->right) p = p->right ;   //Untill p and p->right becomes NULL , Iterate to the rightmost node

    return p ; 
}


node* inOrderSuc(node* p ){

    while(p && p->left) p = p->left ;   //Untill p and p->right becomes NULL , Iterate to the rightmost node

    return p ; 
}





node* Delete(node* p , int key){



    //The initial conditions/When to delete a node 
    if(p == NULL) return NULL ;          //This means root is NULL , nothing to delete , just return 

    if(p->left == NULL && p->right == NULL){   //This means to be deleted node doesn't have any child.In this case just delete the node.      
            delete p ; 
            return NULL ; 
    }


    //The searching part
    if(p->data > key)  p->left = Delete( p->left , key) ;
    else if(p->data < key) p->right = Delete(p->right, key) ; 

    
    else {    //If the key== p->data or key is found then_


            if(Height(p->left) > Height(p->right)){   //that means we may delete from the left subtree of the current node 
                                                     //to make the tree more efficient to search, insert , and delete later on.

                node* temp = inOrderPre(p->left) ;
                p->data = temp->data ;               //updating the data of the current node with its predecessors data .
                                                    //Because now we have to delete the predecessor also 

                p->left = Delete(p->left, temp->data) ; // Deleting the node which contains the predecessors data in the left subtree
                                                        //In this case multiple node can be modified ,so we again call Delete function 

            }
            //Now we have to do it for other case -  if(Height(p->left) <= Height(p->right)) , then we'll replace it with inOrder Successor
            else {
                node* temp = inOrderSuc(p->right) ;
                p->data = temp->data ;               
                p->right = Delete(p->right, temp->data) ; 
            }
    }  

    return p ; 

}


void inOrder(node* p ){
    
    if(p){
        inOrder(p->left) ; 
        cout<<p->data<<" "; 
        inOrder(p->right) ; 
    }
}
int main(){
    
    node* root = NULL ; 
    root = insert(root , 50) ; 
    insert(root,10) ;
    insert(root,40) ;
    insert(root,20) ;
    insert(root,30) ;
    Delete(root, 30) ; 
    inOrder(root) ;    



}