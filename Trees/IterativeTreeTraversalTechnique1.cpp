//this method was implemented by rachit jain in his video
// https://www.youtube.com/watch?v=5BzvEmscu-o

#include <bits/stdc++.h>
using namespace std;

struct node{
    int val;
    node *left, *right;
    node(int x) {
        val = x;
        left = right = NULL;
    }
};



void traversal_trick(node *root) {
    unordered_map<node*, int> cnt;
    //inorder
    //just change the order of cnt[cur]++ and cout<<cur->val<<" " to get preorder and postorder
    stack<node*> S;
    S.push(root);
    while(!S.empty()){
        node* cur = S.top();
        if(cur == NULL) { S.pop(); continue; }
        if (cnt[cur] == 0) S.push(cur->left);
        else if (cnt[cur] == 1) cout << cur->val << " " ;
        else if (cnt[cur] == 2) S.push(cur->right);
        else S.pop();
        cnt[cur]++;
    }
}
int main()
{
    node *root = new node(7); 
    node *t = root;
    root->left = new node(3); root->right = new node(10);
    root->left->left = new node(2); root->left->right = new node(5);
    root->left->left->left = new node(1);
    root->right->left = new node(8); 
    root->right->right = new node(12);
    
    traversal_trick(root);
}