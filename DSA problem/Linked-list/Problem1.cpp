
#include<iostream>
using namespace std;
struct Node
{
    int data;
    struct Node *next;
    Node(int valu){
        data = valu;
        next = NULL;
    }
};
int getSize(Node*head){
   int count = 0;
   Node *Current = head; 
   while(Current !=nullptr){
    count++;
    Current = Current->next;
  }
    return count;
}
int main(){
    Node* head = new Node(34);
    head->next=new Node(12);
    head->next->next=new Node(55);
    head->next->next->next=new Node(42);
    head->next->next->next->next=new Node(11);

    cout<<getSize(head)<<endl;
}
