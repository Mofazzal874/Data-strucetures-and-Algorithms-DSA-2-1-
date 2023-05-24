
#include<iostream>
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

node* insert(node* root , int data){

    if(root == NULL){
        return new node(data);
    }
    
    if(data < root->data){
        root->left =  insert(root->left,data);
    }
    else if(data > root->data){
             root->right = insert(root->right,data);
    }
    return root; 
     
}

bool search(node* root , int val){
    if(root == NULL) return false ; 
    else if(root->data == val) return true ; 
    else if(val <= root->data) return search(root->left , val);
    else return search(root->right , val) ;  
}

void deleteNode(node* root){
}
int main(){

    node* root = NULL ;
    int n;
    cout<<"Enter the number of data: " ; 
    cin>>n ;
    root = insert(root , 50) ;  
    for(int i = 0 ; i < n-1 ; i++){
        int data ; cin>>data ; 
        insert(root ,data) ; 
    }
    cout<<"Enter the value to be searched: " ;
    int val ; 
    cin>>val ;
    if(search(root , val)) {
        cout<<"The value is present in the tree" ;
    } else {
        cout<<"The value is not present in the tree" ;
    }
    return 0;   
}