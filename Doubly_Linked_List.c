#include<stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *prev;
    struct Node *next;
};

struct Node* createNode(int data)
{
    struct Node* newNode = (struct Node *)malloc(sizeof(struct Node *));
    newNode->prev= NULL;
    newNode->next= NULL;
    newNode->data=data;
    return newNode;
}


void insertAtEnd(struct Node **head,int data)
{
    struct Node *temp =*head;
    
    while(temp->next!= NULL)
    {
        temp=temp->next;
    }
    
    struct Node *newNode = createNode(data);
    temp->next = newNode;
    newNode->prev = temp;
    
}

void insertAtBegin(struct Node **head, int data)
{
    struct Node *newNode = createNode(data);

    // If list is not empty
    if (*head != NULL)
    {
        (*head)->prev = newNode;
        newNode->next = *head;
    }

    // Update head
    *head = newNode;
}

void insertAtPos(struct Node **head, int dat, int Pos)
{
    struct Node *newNode = createNode(dat);
    struct Node *trace = *head;
    int Counter=0;
    
    while(!(Counter==Pos))
    {
        trace=trace->next;
        Counter++;
    }

    struct Node *temp = trace->next;

    trace->next = newNode;
    newNode->prev = trace;

    newNode->next = temp;
    //Only update head if you are not traversing
    //     *head = trace; 
}

void deleteAtPos(struct Node **head, int Pos)
{
    struct Node *trace = *head;
    int Counter=0;
    
    while(!(Counter==Pos-1))
    {
        trace=trace->next;
        Counter++;
    }

    struct Node *temp = trace->next;
    trace->next = temp->next;
    temp->prev = trace;

}
void displayNodes(struct Node *head)
{
    struct Node *trace = head;
    while(trace !=NULL)
    {
        printf("Data:%d\n",trace->data);
        trace= trace->next;
    }
    
}
void main()
{
    struct Node *obj= createNode(10);
    
    insertAtEnd(&obj,12);
    insertAtEnd(&obj,13);
    insertAtEnd(&obj,14);
    
     insertAtBegin(&obj,18);
    insertAtPos(&obj,44,3);
    
    deleteAtPos(&obj,3);
    displayNodes(obj);
}    
