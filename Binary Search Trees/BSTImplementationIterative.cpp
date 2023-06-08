
//This implementation does the same work as before , but this works iteratively, not recursively.
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
class node{
    public: 
    node* lchild; 
    int data ; 
    node* rchild;

    node(int val){
        data = val; 
        lchild = rchild = NULL; 

    }
};

node* root = NULL ; 
//as You're making the Create function as void type , so this is necessary 


//Time complexity: O(N)
void create(int val){

    node* tell = root ;//this pointer will iterate through the tree  
    node* behind = root; //this pointer be just behind of tell .So when we'll go to the desired location , we'll link 
                        //the new node with the help of this pointer
    if(root == NULL){
        node* n = new node(val) ;
        root = n ; 
        return ;
    } 
    while(tell){
        behind = tell ;

        if(tell->data > val) tell = tell->lchild;  

        else if(tell->data< val) tell = tell->rchild;

        else if(tell->data == val) {
        cout<<"value "<<val<<" is a duplicate value .Can't be inserted\n"; //in this case duplicate values can occur. 
                                                    //So we are simply returning so that this value can't be inserted
        return ; }                           

    }
    //now we know the desired position of current value.Now we should just link it with the behind node 
    node* n = new node(val) ; 
    if(behind->data > val) behind->lchild = n ; 
    else behind-> rchild = n; 


}



//Time complexity of Search: O(logN)
node* Search(int key){

    node* temp = root ; 
    while(temp){
        if(temp->data == key) return temp; 
        else if(temp->data > key) temp = temp->lchild; 
        else temp= temp->rchild; 
    }
    return NULL ;  
}


void inOrder() {
    unordered_map<node*, int> cnt;
    stack<node*> S;
    S.push(root);
    while(!S.empty()){
        node* cur = S.top();
        if(cur == NULL) { S.pop(); continue; }
        if (cnt[cur] == 0) S.push(cur->lchild);
        else if (cnt[cur] == 1) cout << cur->data << " " ;
        else if (cnt[cur] == 2) S.push(cur->rchild);
        else S.pop();
        cnt[cur]++;
    }
}




int main(){
     node* root = NULL ;
    int n;
    cout<<"Enter the number of data: " ; 
    cin>>n ; 
    cout<<"enter root node: " ; 
    int r ; cin>>r; 
    create(r) ;  
    for(int i = 0 ; i < n-1 ; i++){
        int data ; cin>>data ; 
        create(data) ; 
    }
    cout<<"InOrder Traversal(ascending order traversal): " ; 
    inOrder() ; 
    cout<<endl;
    cout<<"Enter the value to be searched: " ;
    int val ; 
    cin>>val ;
     node* i = Search(val) ; 
    if(i) {
        cout<<"The value is present in the tree :" ;
        cout<<i->data ; 
    } 
    else {
        cout<<"The value is not present in the tree" ;
    }
    return 0;

}

// Terminal:
/*
Enter the number of data: 7
enter root node: 30
15
50
10
20
40
60
InOrder Traversal(ascending order traversal): 10 15 20 30 40 50 60 
Enter the value to be searched: 20
The value is present in the tree :20
*/