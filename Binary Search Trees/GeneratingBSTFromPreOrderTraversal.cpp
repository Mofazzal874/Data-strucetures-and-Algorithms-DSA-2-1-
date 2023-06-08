//this is the simplest approach 

/*Follow the below steps to solve the problem:

1.Create a new Node for every value in the array
2.Create a BST using these new Nodes and insert them according to the rules of the BST(insert mechanism)
3.Print the inorder of the BST to check whether the tree is valid or not (because inOrder traversal will always print sorted order in BST)*/


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


node* create(node* root , int val){

    if(root == NULL) return new node(val) ;

    if( val < root->data) root->left = create(root->left, val) ; 
    else if(val>root->data) root->right = create(root->right, val) ;

    return root;  
    
}
node* buildTree(int pre[] , int n){

    node* root = NULL ; 
    root = create(root , pre[0]) ;  
    for(int i = 1 ; i < n ; i++){
        create(root , pre[i]) ; 
    }
    return root ; 
}

void inOrder(node* root){

    if(root){
        inOrder(root->left) ; 
        cout<<root->data<<" "; 
        inOrder(root->right) ; 
    }
}

int main(){

    int pre[6] = {1, 2, 4, 5, 3, 6} ;
    node* root = buildTree(pre , 6) ;
    inOrder(root) ; 


}


