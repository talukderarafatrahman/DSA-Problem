#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = nullptr;
    }
};

// Function to print the list (for debugging purposes)
void printList(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        cout << current->data;
        if (current->next != nullptr) {
            cout << "->";
        }
        current = current->next;
    }
    cout << endl;
}

// Function to find the middle of the list
Node* findMiddle(Node* head) {
    Node* slow = head;
    Node* fast = head;
    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;  // Slow will be at the middle
}

// Function to reverse a linked list
Node* reverseList(Node* head) {
    Node* prev = nullptr;
    Node* current = head;
    Node* next = nullptr;

    while (current != nullptr) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;  // New head of the reversed list
}

// Function to check if the list is a palindrome
bool isPalindrome(Node* head) {
    if (head == nullptr || head->next == nullptr) {
        return true;  // An empty or single-element list is a palindrome
    }

    // Step 1: Find the middle of the list
    Node* middle = findMiddle(head);

    // Step 2: Reverse the second half of the list
    Node* secondHalf = reverseList(middle);

    // Step 3: Compare both halves
    Node* firstHalf = head;
    while (secondHalf != nullptr) {
        if (firstHalf->data != secondHalf->data) {
            return false;  // Not a palindrome
        }
        firstHalf = firstHalf->next;
        secondHalf = secondHalf->next;
    }

    return true;  // The list is a palindrome
}

int main() {
    // Example 1: 1 -> 2 -> 2 -> 1 (Palindrome)
    Node* head1 = new Node(1);
    head1->next = new Node(2);
    head1->next->next = new Node(2);
    head1->next->next->next = new Node(1);

    if (isPalindrome(head1)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    // Example 2: 1 -> 2 -> 3 -> 1 (Not a palindrome)
    Node* head2 = new Node(1);
    head2->next = new Node(2);
    head2->next->next = new Node(3);
    head2->next->next->next = new Node(1);

    if (isPalindrome(head2)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}
