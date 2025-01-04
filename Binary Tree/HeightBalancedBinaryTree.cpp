#include "bits/stdc++.h"
using namespace std;

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node (int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};

/*
        1
      /   \
     2      3
    / \    / \
   4   5  6   7

*/

int height(Node* root){
      if(root == NULL){
        return 0;
    }
    int lh = height(root->left);
    int rh = height(root ->right);
    return max(lh, rh)+1;
}

bool isBalanced(Node* root){
     if(root == NULL){
        return true;
    }
     if(isBalanced(root->left) == false){
        return false;
     }
     if(isBalanced(root->right)== false){
        return false;
     }

     int lh = height(root->left);
     int rh = height(root->right);
     if(abs(lh - rh) <=1){
        return true;
     }
     else{
        false;
     }
}

int main(){
    Node* root = new Node(1);
    root->left =  new Node(2);
    root->left->left = new Node(3);
   
    //Height Balanced Tree
    if(isBalanced(root)){
        cout<<"Balanced tree"<<"\n";
    }
    else{
        cout<<"unbalanced tree"<<"\n";
    }
    
    
    return 0;

}