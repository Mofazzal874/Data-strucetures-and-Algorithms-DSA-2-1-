//This implementation is for creating a tree with linked representation
//But the traversing techniques are iterative

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
    
    stack<node*> st;
    st.push(p) ;  
    while(!st.empty()){
        p = st.top(); 
        cout<<p->data<<" ";
        st.pop() ;  
        if(p->rchild) st.push(p->rchild);
        if(p->lchild) st.push(p->lchild) ; 
    } 
}


void Tree::  inOrder(node* p){

   stack<node*> st;
    while(p || !st.empty()){ //if any of these two conditions is true ,then loop will continue 
                                //at first !st.empty() will not be checked.Though it is false for first time , the 
                                //loop will continue to iterate

        if(p){
            st.push(p) ; 
            p = p->lchild; 

        }
        else { 
            cout<<st.top()->data<<" " ; 
            st.pop() ; 
            p = p->rchild; 
        } 

    }

    
}





//steps for the post order traversall(GPT generated)
// steps:
/*It declares a pointer prev and initializes it to NULL. This pointer keeps track of the previously visited node.

1.The while loop executes until the current node p is NULL and the stack is empty.

2.Inside the loop, the code checks if the current node p is not NULL. If so, it means there are still unvisited nodes in the left subtree. In this case, the current node p is pushed onto the stack, and p is updated to its left child (p = p->lchild).

3.If the current node p is NULL, it means we have finished traversing the left subtree or right subtree of a node. We need to visit the current node and move to the next node based on the post-order traversal.

4.The code retrieves the top node from the stack (p = st.top()).

5.It checks if the right child of the current node is NULL or if it has already been visited (p->rchild == NULL || p->rchild == prev). If this condition is true, it means we have visited both subtrees of the current node.

6.In that case, the code prints the data of the current node (cout << p->data << " "), pops the node from the stack (st.pop()), updates the prev pointer to the current node, and sets p to NULL. This is done to ensure that we move to the next node in the stack in the next iteration.

7.If the right child of the current node is not NULL and has not been visited yet, it means we still need to traverse the right subtree. The code updates p to the right child (p = p->rchild).
*/

void Tree:: postOrder(node* p){

   stack<node*> st;
   node* prev = NULL ; 
   while(p || !st.empty()){
    if(p) {
        st.push(p) ; 
        p = p->lchild; 
    }
    else {
        p = st.top() ; 
        if(p->rchild == NULL || p->rchild == prev){
            cout<<p->data<<" " ; 
            st.pop() ; 
            prev = p ; 
            p = NULL; 
        }
        else {
            p = p->rchild ; 
        }
    }
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
    // cout<<"\nLevelOrder: ";
    // t.levelOrder(t.root);
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