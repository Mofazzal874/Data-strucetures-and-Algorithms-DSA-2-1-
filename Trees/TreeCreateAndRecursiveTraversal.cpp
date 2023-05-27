//This implementation is for creating a tree with linked representation
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

class node{
    public:
    node* lchild; 
    int data; 
    node* rchild; 
    node(int data){
        this->data = data; 
        lchild = NULL; 
        rchild = NULL; 
    }
};

class Tree{
    public:
        node* root;
    Tree(){ root = NULL ; }
    void createTree() ; 
    void preOrder(node* p) ;
    void postOrder(node* p) ;
    void inOrder(node* p) ;
    void levelOrder(node* p) ;


};
void Tree::createTree(){
    node* p , *temp ; 
    queue<node*> q;
    int x; 
    cout<<"Enter root node value: " ; 
    cin>>x ;  
    root = new node(x) ; 
    q.push(root) ; 
    while(!q.empty()){
        p = q.front() ;
        q.pop();
        cout<<"Enter left child of(enter -1 if have not any) "<<p->data<<" : " ;
        cin>>x;
        if(x!= -1) p->lchild = new node(x) ,q.push(p->lchild) ;//pushing left child
         
        cout<<"Enter right child of(enter -1 if have not any) "<<p->data<<" : " ;
        cin>>x ;
        if(x!=-1) p->rchild = new node(x) , q.push(p->rchild) ; //pushing right child 
    } 
}
void Tree :: preOrder(node* p){
    if(p){
        cout<<p->data<<" ";
        preOrder(p->lchild);
        preOrder(p->rchild);
    }
}
void Tree:: postOrder(node* p){
    if(p){
        postOrder(p->lchild);
        postOrder(p->rchild);
        cout<<p->data<<" ";
    }
}
void Tree::  inOrder(node* p){
    if(p){
        inOrder(p->lchild);
        cout<<p->data<<" ";
        inOrder(p->rchild);
    }
}

void Tree:: levelOrder(node* p){

    queue<node*> q;
    cout<<p->data<<" ";
    q.push(p);
    while(!q.empty()){
        p = q.front();
        q.pop();
        if(p->lchild){
            cout<<p->lchild->data<<" ";
            q.push(p->lchild);
        }
        if(p->rchild){
            cout<<p->rchild->data<<" ";
            q.push(p->rchild);
        }
    }
}

int main(){
    Tree t;
    t.createTree();
    cout<<"PreOrder: ";
    t.preOrder(t.root);
    cout<<"\nPostOrder: ";
    t.postOrder(t.root);
    cout<<"\nInOrder: ";
    t.inOrder(t.root);
    cout<<"\nLevelOrder: ";
    t.levelOrder(t.root);
    return 0;
    
}
//Terminal:
/*Enter root node value: 8
Enter left child of(enter -1 if have not any) 8 : 3
Enter right child of(enter -1 if have not any) 8 : 5
Enter left child of(enter -1 if have not any) 3 : 4
Enter right child of(enter -1 if have not any) 3 : 9
Enter left child of(enter -1 if have not any) 5 : 7
Enter right child of(enter -1 if have not any) 5 : 2
Enter left child of(enter -1 if have not any) 4 : -1
Enter right child of(enter -1 if have not any) 4 : -1
Enter left child of(enter -1 if have not any) 9 : -1
Enter right child of(enter -1 if have not any) 9 : -1
Enter left child of(enter -1 if have not any) 7 : -1
Enter right child of(enter -1 if have not any) 7 : -1
Enter left child of(enter -1 if have not any) 2 : -1
Enter right child of(enter -1 if have not any) 2 : -1
PreOrder: 8 3 4 9 5 7 2
PostOrder: 4 9 3 7 2 5 8
InOrder: 4 3 9 8 7 5 2
LevelOrder: 8 3 5 4 9 7 2
*/ 