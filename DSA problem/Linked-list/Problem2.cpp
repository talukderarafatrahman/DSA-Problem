
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

int getSize(Node*head){
    int count=0;
    Node*Current=head;
    while(Current!=nullptr){
        count++;
        Current=Current->next;
    }
    return count;
}

int findMidVal(Node* head){
    int size = getSize(head);
    int midIndex = size / 2;
    Node* current = head;

    for (int i = 0; i < midIndex; i++) {
        current = current->next;
    }

    return current->data;

}

int main(){
    Node*head=new Node(34);
    head->next=new Node(12);
    head->next->next=new Node(55);
    head->next->next->next=new Node(42);
    head->next->next->next->next=new Node(11);

    int midValue = findMidVal(head);
    cout<< findMidVal ;


}
