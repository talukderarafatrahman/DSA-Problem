// #include<stdio.h>
// #include<iostream>

#include<bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    node *link;
};
//insert
void inSertFront(node *header, int data);
void inSertlast(node *header, int data);
void inSertAt(node *header, int data, int index);
void inSertBeforeValue(node *header, int data, int vale);
void inSertSortOrder(node *header, int data);

//Update
void updateFront(node *header, int data);
void updateLast(node *header, int data);
void updateAt(node *header, int data, int index);
void updateValue(node *header, int data, int value);

//Delete
void deleteFront(node *header);
void deleteLast(node *header);
void deleteAt(node *header, int index);
void deleteValue(node *header, int value);

//Search
int searchIndexOfValue(node *header, int data);
int ValueOfIndex(node *header, int index);

// printf
void printList(node *header);
void printList(node *header)
{
    node *ptr = header ->link;
    while (ptr  != NULL)
    {
        cout << ptr->data << " ";
        ptr = ptr->link;
    }
    cout << endl;
    
}

int searchIndexOfValue(node *header, int data)
{
    node *ptr = header ->link;
    int index = 0;

    while (ptr ->data != data && ptr !=NULL)
    {
        index++;
        ptr = ptr ->link;
    }
    if(ptr ->data == data)
    return index;
    else
    return -1;    
}

///header - n0 -n1 -n2 - newNode - n3 - n4 - n5

int valueOfIndex(node *header, int index)
{
    node *ptr = header->link;
    int i = 0;
    do
    {
        if(ptr == NULL)
        {
            cout << "Array out of Bound Or Emty List" << endl;
            return - 9999;
        }
        else
        {
            ptr = ptr->link;
            i++;
        }
    } while (i != index);
    return ptr->data;
    
}

//header - n1 - n2 - n3

void updateFront(node *header, int data)
{
    // node *ptr = header->link;
    // ptr ->data = data;
    header ->link->data = data;

}
void updateLast(node *header, int data)
{
    node *ptr = header;
    while (ptr ->link != NULL)
    {
        ptr = ptr->link;
    }
    ptr ->data = data;
}

//header n0 n1 n2 n3
void updateAt(node *header, int data, int index)
{
    node *ptr = header;
    int indexCheck = -1;

    while (indexCheck < index -1 && ptr ->link != NULL)
    {
       indexCheck++;
       ptr = ptr->link;
    }
    if(indexCheck+1 != index)
    {
        return;
    }
    ptr ->link ->data = data;
}

void updateValue(node *header, int data, int value)
{
    int index = searchIndexOfValue(header, value);
    updateAt(header, data, index);
}

//header n0 n1 n2 n3
void deleteFront(node *header)
{
    if(header ->link == NULL)
    return;

    node *ptr = header ->link;

    header -> link = ptr ->link;
    free(ptr);
}

void deleteLast(node *header)
{
    if(header ->link == NULL)
    return;

    node *ptr = header;
    while (ptr ->link ->link !=NULL)
    {
        ptr = ptr->link;
    }
    free(ptr ->link);
    ptr ->link = NULL;
    
}

//header n0 n1 n3
void deleteAt(node *header, int index)
{
    if(header ->link == NULL)
    return;

    node *ptr = header;
    int indexCheck = -1;

    while (indexCheck < index -1 && ptr ->link != NULL)
    {
       indexCheck++;
       ptr = ptr->link;
    }
    if(indexCheck+1 != index)
    {
        return;
    }
    node *temp = ptr ->link ->link;
    free(ptr->link);
    ptr ->link = temp;

}

void deleteValue(node *header, int value)
{
    int index = searchIndexOfValue(header, value);
    deleteAt(header, index);
}

// 41
// 465 < 41
// 333 == 465 333 41
// 70 == 465 333 70 41
// 500

void inSertSortOrder(node *header, int data)
{
    node *ptr = header ->link;
    node *pred;
    node *newNode = (node *) malloc(sizeof(node));

    if(ptr == NULL || ptr ->data > data)
    {
        newNode ->data = data;
        newNode ->link = ptr;
        header ->link = newNode;
    }
    else
    {
        pred = header;
        while (ptr != NULL && ptr->data < data) {
        pred = ptr;
        ptr = ptr->link;
    }
        newNode->data = data;
        newNode->link = pred->link;
        pred->link = newNode;
        
    }
}

// header - newNode - n1 - n2 - n3

void inSertFront(node *header, int data)
{
    node *newNode = (node *) malloc(sizeof(node));
    if(newNode == NULL)
    {
        cout << "Memory Not Available Function Not Compiled" <<endl;
    }
    else
    {
        newNode->data = data;
        newNode->link = header->link;
        header->link = newNode;
    }
}

// header -n1 - n2 - n3 - newNode
void inSertlast(node *header, int data)
{
    node *ptr = header;
    while (ptr ->link != NULL)
    {
        ptr = ptr ->link;
    }
    node *newNode = (node *) malloc(sizeof(node));
    if(newNode == NULL)
    {
        cout << "Memory Not Available Function Not Compiled" <<endl;
    }
    else
    {
        newNode->data = data;
        newNode->link = ptr->link;
        ptr->link = newNode;
    }

}
//header - n0 - n1 -n2 - newNod - n3 - n4 - n5
void inSertAt(node *header, int data, int index)
{
    node *ptr = header;
    int indexCheck = -1;
    //MODIFIED
    while (indexCheck < index -1 && ptr ->link != NULL)
    {
       indexCheck++;
       ptr = ptr->link;
    }
    if(indexCheck+1 != index)
    {
        cout <<"Out of Bound" <<endl;
    }
    else
    {
        node *newNode = (node *)malloc(sizeof(node));
        if(newNode == NULL)
        {
            cout << "Memory Not Avaiable Function Not Compiled" <<endl;
        }
        else
        {
        newNode->data = data;
        newNode->link = ptr->link;
        ptr->link = newNode;
        }
    }
}
void inSertBeforeValue(node *header, int data, int vale)
{
    int index = searchIndexOfValue(header,vale);
    inSertAt(header, data, index);
}

int main() {
    node *header = (node *)malloc(sizeof(node));
    header->link = NULL;

    // Testing the functions
    inSertFront(header, 10);
    inSertlast(header, 20);
    inSertAt(header, 15, 1);
    inSertSortOrder(header, 12);

    cout << "List after insertion: ";
    printList(header);

    updateFront(header, 5);
    updateLast(header, 25);
    updateAt(header, 17, 2);

    cout << "List after updates: ";
    printList(header);

    deleteFront(header);
    deleteLast(header);

    cout << "List after deletions: ";
    printList(header);

    return 0;
}