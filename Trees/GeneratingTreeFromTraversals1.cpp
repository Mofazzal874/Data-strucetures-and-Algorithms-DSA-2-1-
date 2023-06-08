// Trees can be generated only if Inorder+ preOrder or InOrder+ PostOrder is given


//In this implementation it is assumed that Inorder and PreOrder is given 

/*
Algorithm: buildTree() 

1.Pick an element from Preorder. Increment a Preorder Index Variable (preIndex in below code) to pick the next element in the next recursive call. 
2.Create a new tree node tNode with the data as the picked element. 
3.Find the picked element’s index in Inorder. Let the index be inIndex. 
4.Call buildTree for elements before inIndex and make the built tree as a left subtree of tNode. 
5.Call buildTree for elements after inIndex and make the built tree as a right subtree of tNode. 
6.return tNode.
*/


//Time complexity: O(n^2)
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

//creating node class to create every node 
class node{
    public:
    node* lchild ; 
    int data; 
    node* rchild; 

    node(int val){
        data = val ; 
        lchild = rchild = NULL; 
    }
} ;

int search(int in[], int inStart  , int inEnd ,int val){

    for(int i = inStart ; i <= inEnd ; i++){
        if(in[i] == val) 
        return i ; 
    }
}

node* buildTree(int in[] , int pre[] , int inStart , int inEnd){

    static int preIndx = 0 ; 

    if(inStart > inEnd) return NULL ; 

    node* tNode = new node(pre[preIndx++]) ;

    if(inStart == inEnd) return tNode ; 

    int inIndx =search(in,inStart , inEnd , tNode->data) ;
    tNode->lchild =buildTree(in , pre , inStart , inIndx-1) ; 
    tNode->rchild = buildTree(in , pre , inIndx+1 , inEnd) ; 
    return tNode;  

}

void inOrder(node* root){

    if(root == NULL) return ; 
    inOrder(root->lchild) ; 
    cout<<(root->data)<<" " ; 
    inOrder(root->rchild) ; 
}



int main(){

    int in[] = {4, 2, 5, 1, 6, 3} ; 
    int pre[] = {1, 2, 4, 5, 3, 6} ; 
    node* root = buildTree(in , pre , 0 , 5) ; 
    cout<<"InOrder Traversal of the constructed Tree is: \n" ; 
    inOrder(root) ;  
}
//Terminal:
// InOrder Traversal of the constructed Tree is: 
// 4 2 5 1 6 3 