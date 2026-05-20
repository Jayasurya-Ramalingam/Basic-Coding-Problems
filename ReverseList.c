#include <stdio.h>

struct Node{
    int data;
    struct Node *next;
};

struct Node* createNode(int dat)
{
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node*));
    newNode->data = dat;
    newNode->next=NULL;
    
    return newNode;
}

void reverseList(struct Node **head)
{
    struct Node* current = *head;
    struct Node* prev = NULL;
    struct Node* next = NULL;
    
    while(current!= NULL)
    {
        //1. Save Next step
        next = current->next;
        //2. current-> next should previous
        current->next = prev;
        
        //3. prev Current 
        prev = current;
        current = next;
    }
    
    *head = prev;
}

void displayNode(struct Node* temp)
{
    while(temp!=NULL)
    {
        printf("Data:%d\n",temp->data);
        temp=temp->next;
    }
}
void main()
{
    struct Node*obj = createNode(8);
    obj->next = createNode(9);
    obj->next->next = createNode(10);
    obj->next->next->next = createNode(11);
    obj->next->next->next->next = createNode(12);
    obj->next->next->next->next->next = createNode(13);
    
    displayNode(obj);
    
    //Reverse List
    reverseList(&obj);
    
    displayNode(obj);
}
