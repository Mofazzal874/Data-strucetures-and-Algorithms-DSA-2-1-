//The Below implementation Insert , search ,delete uses recursion. 
//To see the iterative implementation go to " BSTImplementation_Iterative.cpp"

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

class node{
    public:
    int data;
    node* left ;
    node* right ; 
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

node* search(node* root , int val){
    if(root == NULL|| root->data == val) return root ; 
    
    else if(val < root->data) return search(root->left , val);

    else return search(root->right , val) ;  
}


//this function is required if the to be deleted node has two children 
//then we have to find the minimum node in the right subtree ;
//That means we are searching for InOrder successor (leftmost element in the right subtree) 
node* minValueNode(node* root){

        node* current = root ; 
        //loop down to find the leftmost leaf
        while(current && current->left){
            current = current->left ; 
        }
        return current ; 
}
node* deleteNode(node* root , int key){         //Actually this function is doing (searching + deleting) both

    //base case
    if(root == NULL) return root ;
    //now the searching part 
    if(key < root->data) root->left = deleteNode(root->left , key)  ;
    else if(key > root->data) root->right = deleteNode(root->right , key) ;

    //the below part means key == root->data , now how many case can be possible ?
    else {
        //case-01: to be deleted node has no child
        //then simply return NULL 
        if(root->left== NULL && root->right == NULL){
            return NULL ; 
        }
        //case-02 : to be deleted node has only one child
        //for say , it has only right child. Then simply return the 
        //right child 
        else if(root->left == NULL){
            node* temp = root->right ;
            delete root; 
            return temp ;  
        }
        //if to be deleted node has  only left child 
        else if (root->right == NULL){
            node* temp = root->left ; 
            delete root ; 
            return temp  ;
        }

        //case-03: to be deleted node hase both left and right child 
        //Then
        //step-01:  get the inOrder successor(the minimum value node in the right subtree of the deleted node) 
        else {
            node* temp = minValueNode(root->right);
        //step-02:
        //copying the inOrder successor's content to this node
        root->data = temp->data; 
        //delete the inOrder successor 
        root->right = deleteNode(root->right , temp->data) ; 
        }
        return root; 
    } 


}
void inOrder(node* root){
    if(root){
        inOrder(root->left) ; 
        cout<<root->data<<" "; 
        inOrder(root->right) ; 
    }
}
int main(){

    node* root = NULL ;
    int n;
    cout<<"Enter the number of data: " ; 
    cin>>n ; 
    cout<<"enter root node: " ; 
    int r ; cin>>r; 
    root = insert(root , 50 ) ;//First time inserting.
                               // So root must be created .After that root of every subtree will be assigned recursively  
    for(int i = 0 ; i < n-1 ; i++){
        int data ; cin>>data ; 
        insert(root ,data) ; 
    }
    cout<<"InOrder Traversal(ascending order traversal): " ; 
    inOrder(root) ; 
    cout<<endl;
    cout<<"Enter the value to be searched: " ;
    int val ; 
    cin>>val ;
     node* i = search(root,val) ; 
    if(i) {
        cout<<"The value is present in the tree :" ;
        cout<<i->data ; 
    } 
    else {
        cout<<"The value is not present in the tree" ;
    }
    return 0;   
}