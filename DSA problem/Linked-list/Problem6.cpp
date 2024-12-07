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

Node* reverseList(Node* head) {
    Node* current = head;
    Node* temp = nullptr;

    // Swap next and prev for all nodes
    while (current != nullptr) {
        temp = current->next;
        current->next = current->next;
        current->next = temp;
        current = current->next; // Move to the next node in the original list (which is now the previous node)
    }

    // After the loop, 'temp' will be pointing to the new head
    if (temp != nullptr) {
        head = temp->next;
    }

    return head;
}

int main() {
    // Create a doubly linked list: 7 <-> 12 <-> 8 <-> 65 <-> 10
    Node* head = new Node(7);
    head->next = new Node(12);
    head->next->next = head;
    head->next->next = new Node(8);
    head->next->next->next = head->next;
    head->next->next->next = new Node(65);
    head->next->next->next->next = head->next->next;
    head->next->next->next->next = new Node(10);
    head->next->next->next->next->next = head->next->next->next;

    // Print the original list
    cout << "Original list: ";
    printList(head);

    // Reverse the doubly linked list
    head = reverseList(head);

    // Print the reversed list
    cout << "Reversed list: ";
    printList(head);

    return 0;
}