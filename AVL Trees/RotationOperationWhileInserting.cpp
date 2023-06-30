#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
class node {
    public:
    node* left; 
    int data; 
    int height ; 
    node* right ; 
    
    node(){
        left = right = NULL; 
    }
    node(int val){
        left = right = NULL; 
        data = val; 

    }
}*root = NULL;

int nodeHeight(node* p){
    int hl , hr ; 
    hl = ( p && p->left)?p->left->height:0;    // you can also write it like this -
                                               //if(p && p->left) hl = p->left->height ;
                                              // else  hl = 0 ; 
    hr = (p && p->right)?p->right->height:0;
     
    return hl>hr? hl+1:hr+1 ; //return the maximum of hl and hr 

}

int balanceFactor(node* p ){

    int hl , hr ; 
    //find the height of lefft subtree and right subtree
    hl=(p && p->left)?p->left->height:0;

    hr=(p && p->right)?p->right->height:0;

    //return BF = hl - hr ; 
    return hl-hr ;

}

node* LLRotation(node* p){

    node* pl ;
    node* plr ; 
    pl = p->left ; 
    plr = pl->right ;

    //now we need to reconfigure according to LL rotation
    pl->right = p ; 
    p ->left = plr ; 
    //now we need to reassign height of pl , p 
    p->height = nodeHeight(p) ;
    pl->height = nodeHeight(pl) ;


    if(root == p) root = pl ; //if p is the root then assign pl as root 

    return pl ;     //returning pl as new root of a subtree which is rotated 

}

node* RRRotation(node* p){
    node* pr = p->right ; 
    node* prl = pr->left ;

    //now we have to reconfigure according to RR rotation 
    pr->left = p ; 
    p->right = prl ; 

    //now we have adjust height for p , pr 
    p->height = nodeHeight(p) ; 
    pr->height = nodeHeight(pr) ; 

    if(root == p) root = pr ; 

    return pr ;   

}
node* LRRotation(node* p){
   node* pl = p->left ; 
   node* plr = pl->right ;

   //now we have to relocate them as according to LR Rotation 

   pl->right = plr->left ; 
   p->left  = plr->right ; 
   plr ->left = pl ; 
   plr->right = p ; 

   //now we need to reconfigure the heights of changed nodes.
   //we have to assign height for all p , pl , plr as all of their nodes are changed
   p->height = nodeHeight(p)  ; 
   pl->height = nodeHeight(pl) ; 
   plr->height = nodeHeight(plr) ; 

   if(root == p ) root = plr ; 

   return plr; 

}
node* RLRotation(node* p){

    node* pr = p->right ; 
    node* prl = pr->left ; 

    //now we to reconfigure according to RL rotation 
    p->right = prl->left ; 
    pr->left = prl->right ; 
    prl->left = p ; 
    prl->right = pr ; 

    //now we have to recalculate the height of p , pr , prl as all of their node is changed .
    p->height = nodeHeight(p)  ; 
    pr->height = nodeHeight(pr) ; 
    prl->height = nodeHeight(prl) ;


    if(root == p) root = prl  ; 

    return prl ; 
}
node* RInsert(node *p , int key){

    node* n = new node(key) ;
    if(p == NULL) {
        n->height = 1; //if there is only one node ,
                        // we set the height as 1 .it can also be set from 0.But we start it from 1 for simplification 
        return n ;
    }
    if(key < p->data) p->left=RInsert(p->left,key);
    else if( key> p->data)  p->right=RInsert(p->right,key);

    //now we should also update the height of the current node in returning time(when left and right assigning is over)

    p->height = nodeHeight(p) ; //height of p should be equal to the maximum of the height 
                                //of the left and right subtree . To assign max(hl ,hr) into the p->height , 
                                //we make a function, nodeHeight



    //Now we should perform the rotation operation to make the tree a balanced Binary Tree(or a AVL Tree)
    //for this we have to check if the balance factor is okay for the current node 


    //see note khata for the info about LL , RR , LR , RL and their relation with Balance factors
    if(balanceFactor(p) == 2 && balanceFactor(p->left) == 1){
        return LLRotation(p) ; 
    }
    else if(balanceFactor(p) == 2 && balanceFactor(p->left) == -1) {
        return LRRotation(p) ;

    }
    else if(balanceFactor(p) == -2 && balanceFactor(p->right) == -1) {
        return RRRotation(p) ;

    }
    else if(balanceFactor(p) == -2 && balanceFactor(p->right) == 1) {
        return RLRotation(p) ;

    }
    

    return p ;
}


void levelOrder(node* p){

    queue<node*> q;
    cout<<p->data<<" ";
    q.push(p);
    while(!q.empty()){
        p = q.front();
        q.pop();
        if(p->left){
            cout<<p->left->data<<" ";
            q.push(p->left);
        }
        if(p->right){
            cout<<p->right->data<<" ";
            q.push(p->right);
        }
    }

    cout<<"\n"  ; 
}

int main(){


    //See the example of -"Creating AVL Tree" in NoteKhata for handwritten operation in each steps
    //keys: 10, 20, 30, 25, 28, 27, 5 

    root = RInsert(root, 10) ; 
    RInsert(root , 20) ;
    RInsert(root , 30) ;
    levelOrder(root) ; 
    RInsert(root, 25) ; 
    levelOrder(root) ;
    RInsert(root , 28) ; 
    levelOrder(root) ; 
    RInsert(root , 27) ; 
    levelOrder(root) ; 
    RInsert(root, 5) ; 
    levelOrder(root) ; 

    return 0 ; 

    


    
}