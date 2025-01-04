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
//BalanceBST
Node* BalanceBST(int arr[], int start, int end){
    if(start > end){
        return NULL;
    }
    int mid = (start + end) / 2;
    Node* root = new Node(arr[mid]);

    root->left = BalanceBST(arr, start, mid-1);
    root->right = BalanceBST(arr, mid+1, end);

    return root;
}
//preorder
Node* constructBST(int preorder[], int* preorderIdx, int key,int min, int max, int n){
    if(*preorderIdx >= n){
        return NULL;
    }
    Node* root = NULL;
    if(key > min && key < max){
        root = new Node(key);
        *preorderIdx = *preorderIdx + 1;

        if(*preorderIdx < n){
            root->left = constructBST(preorder, preorderIdx,preorder[*preorderIdx],min,key,n);
        }
        if(*preorderIdx < n){
            root->left = constructBST(preorder, preorderIdx,preorder[*preorderIdx],min,key,n);
        }
    }
    return root;
}



Node* inorderSucc(Node* root){
    Node* curr = root;
    while (curr && curr->left != NULL)
    {
        curr = curr->left;
    }
    return curr;
    
}

//DeleteBST
Node* deleteInBST(Node* root, int key){
    if(key < root->data){
        root->left = deleteInBST(root->left, key);
    }
    else if(key > root->data){
        root->right = deleteInBST(root->right,key);
    }
    else{
        if(root->left == NULL){
            Node* temp = root->right;
            free(root);
            return temp;
        }
        else if(root->right == NULL){
            Node* temp = root->left;
            free(root);
            return temp;
        }
        Node* temp = inorderSucc(root->right);
        root->data = temp->data;
        root->right = deleteInBST(root->right, temp->data);
    }
    return root;
}

//SearchBST
Node* searchInBST(Node* root, int key){
    if(root == NULL){
        return NULL;
    }
    if(root->data == key){
        return root;
    }
    if(root->data > key){
        return searchInBST(root->left, key);
    }
    //data < key
    return searchInBST(root->right, key);
}

//InsertBST
Node* insertBST(Node *root, int val){
    if(root == NULL){
        return new Node(val);
    }
    if(val < root->data){
        root->left = insertBST(root->left, val);
    }else{
        root->right = insertBST(root->right, val);
    }
    return root;
}
void inorder(Node *root){
    if(root == NULL){
        return;
    }
    inorder(root->left);
    cout << root->data <<" ";
    inorder(root->right);
}

void printPreorder(Node* root){
    if(root == NULL){
        return;
    }
    cout << root->data<<" ";
    printPreorder(root->left);
    printPreorder(root->right);
}
void preorderPrint(Node* root){
    if(root == NULL){
        return;
    }
    cout << root->data <<" ";
    preorderPrint(root->left);
    preorderPrint(root->right);
}

int main(){
    Node*root = NULL;
    root = insertBST(root, 5);
    insertBST(root, 1);
    insertBST(root, 3);
    insertBST(root, 4);
    insertBST(root, 2);
    insertBST(root, 7);

    //print inorder
    inorder(root);
    cout << endl;
    root = deleteInBST(root,5);
    inorder(root);
    cout << endl;
    return 0;

    //SearchBST
    if(searchInBST(root, 5)== NULL){
        cout <<"Key doesn't exist";
    }else{
        cout << "key exists";
    }
    return 0;

    root = deleteInBST(root, 5);
    return 0;

    int preorder[] = {10,2,1,13,11};
    int n=5;
    int preorderIdx = 0;
    Node* root = constructBST(preorder, &preorderIdx, preorder[0], INT_MIN, INT_MAX, n);
    printPreorder(root);

    return 0;

    //BalanceBST
    int arr[] = {10,20,30,40,50};
    Node* root = BalanceBST(arr, 0,4);
    preorderPrint(root);
    cout << endl;
    return 0;
}