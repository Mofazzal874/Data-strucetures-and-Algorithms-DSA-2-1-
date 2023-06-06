//this is the same code as before 
//But this takes O(n) time 
//Here we use an unordered_map for the searching .Unordered_map makes a hash Table to search .So
// Search can happen in O(1) time
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




node* buildTree(int in[] , int pre[] , int inStart , int inEnd , unordered_map<int, int> &mp){

    static int preIndx = 0 ; 

    if(inStart > inEnd) return NULL ; 

    int curr = pre[preIndx++] ;
    node* tNode = new node(curr) ;

    if(inStart == inEnd) return tNode ;

    int inIndx =mp[curr] ;

    tNode->lchild =buildTree(in , pre , inStart , inIndx-1,mp) ; 
    tNode->rchild = buildTree(in , pre , inIndx+1 , inEnd ,mp) ; 
    return tNode;  

}


node* buildwrap(int in[] , int pre[] , int len)
{
    unordered_map<int , int> mp ; 
    for(int i = 0 ; i<len; i++) mp[in[i]] = i ; 
    return buildTree(in, pre , 0 , len-1 , mp ) ; 
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
    node* root = buildwrap(in , pre , 6) ; 
    cout<<"InOrder Traversal of the constructed Tree is: \n" ; 
    inOrder(root) ;  
}
