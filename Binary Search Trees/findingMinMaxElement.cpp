//given a BST , find the max and min element of that BST
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

node* insert(node* &root , int data){

    if(root == NULL){
        root = new node(data);
    }
    else{
        if(data < root->data){
            root->left = insert(root->left,data);
        }
        else{
            root->right = insert(root->right,data);
        }
    }
}

int findMin(node* &root){
    if(root == NULL) {
        cout<<"Error: Tree is Empty\n" ;
        return -1; 
    }
    node* temp = root ; 
        while(temp->left!= NULL){
            temp = temp->left ; 
        }
        return temp->data ;


}
int main(){

    cout<<"Enter the number of data: " ; 
    int n ; cin>>n ; 
    node* root = NULL ;
    for( int i = 0 ; i < n ;i++){
        int data ; cin>>data ;
        insert(root , data);
    }
    cout<<"Minimum Number in the BST: " ; 
    cout<<findMin(root) ; 
    return 0;   
}
