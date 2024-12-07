#include<iostream>

using namespace std;

struct Node{
    int data;
    struct Node*next;
    Node(int val){
        data=val;
        next=NULL;
    }
};

int printList(Node*head){
    Node*current=head;
    while(current !=NULL){
        cout<<current->data;
        if(current->next !=NULL){
            cout<<"->";
        }
        current=current->next;
    }
    cout<<endl;
}

Node*insertinList(Node*head,int num){
    Node*newNode=new Node(num);
    if(head==NULL || num<head->data){
        newNode->next=head;
        return newNode;
    }
    Node*current=head;
    while(current->next !=NULL && current->next->data<num){
        current=current->next;
    }
    newNode->next=current->next;
    current->next=newNode;
}

int main(){
    Node*head=new Node(1);
    head->next=new Node(4);
    head->next->next=new Node(6);
    head->next->next->next=new Node(7);
    head->next->next->next->next=new Node(9);
    head->next->next->next->next->next=new Node(11);

    printList(head);

    int num;
    cin>>num;

    head=insertinList(head,num);
    printList(head);
}

