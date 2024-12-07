
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
int main(){
    Node*head=new Node(1);
    head->next=new Node(2);
    head->next->next=new Node(1);
    head->next->next->next=new Node(2);
    head->next->next->next->next=new Node(1);
    head->next->next->next->next->next=new Node(3);
    head->next->next->next->next->next->next=new Node(1);

    int num;
    cin>>num;

    Node* ptr = head;
    int count = 0;
    while (ptr != NULL) {
        if (ptr->data == num) {
            count++;
        }
        ptr = ptr->next;
    }
    cout<<count<<endl;
    
}
