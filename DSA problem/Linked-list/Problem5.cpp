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

void printList(Node*head){
    Node*current=head;
    while(current!=NULL){
        cout<<current->data;
        if(current->next!=NULL){
        cout<<"->";
    }
    current=current->next;

    }
    cout<<endl;
}

Node*deleteEvenNumber(Node*head){
    while(head!=NULL && head->data % 2 == 0){
        Node*temp=head;
        head=head->next;
        delete temp;
    }
    Node*current=head;
    while(current != NULL && current->next != NULL){
        if(current->next->data % 2 == 0){
            Node*temp=current->next;
            current->next=current->next->next;
            delete temp;
        }
        else{
            current=current->next;
        }
    }
    return head;

}

int main(){
    Node*head=new Node(1);
    head->next=new Node(4);
    head->next->next=new Node(6);
    head->next->next->next=new Node(7);
    head->next->next->next->next=new Node(9);
    head->next->next->next->next->next=new Node(11);

    //printList(head);
    head=deleteEvenNumber(head);

    printList(head);
}