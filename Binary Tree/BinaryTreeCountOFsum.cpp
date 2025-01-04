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

int countNodes(Node* root){
    if(root == NULL)
    return 0;
}
return countNodes(rot->left)+countNodes(root->right)+1;



int main(){
    struct Node* root = new Node(1);
    root->left =  new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->left = new Node(7);

    //Level Order Traversal
 cout<<countNodes(root)<<"\n";
    
    return 0;

}