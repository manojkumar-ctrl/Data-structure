#include<stdio.h>
#include<stdlib.h>
struct node
{
int data;
struct node *next;
};
struct node *head = NULL;
void push(int val)
{
//create new node
struct node *newNode = malloc(sizeof(struct node));
newNode->data = val;
//make the new node points to the head node
newNode->next = head;

head = newNode;
}
void pop()
{

struct node *temp;
if(head == NULL)
printf("Stack is Empty\n");
else
{
printf("Popped element = %d\n", head->data);
//backup the head node
temp = head;

head = head->next;
//free the poped element's memory
free(temp);
}
}

void enqueue(int val)
{
struct node *newNode = malloc(sizeof(struct node));
newNode->data = val;
newNode->next = NULL;

if(front == NULL && rear == NULL)
//make both front and rear points to the new node
front = rear = newNode;
else
{
//add newnode in rear->next
rear->next = newNode;
//make the new node as the rear node
rear = newNode;
}
}
void dequeue()
{
//used to free the first node after dequeue
struct node *temp;
if(front == NULL)
printf("Queue is Empty. Unable to perform dequeue\n")
;
else
{
temp = front;
front = front->next;
//if front == NULL, set rear = NULL
if(front == NULL)
rear = NULL;

free(temp);
}
}
void printList()
{
struct node *temp = front;
while(temp)
{
printf("%d->",temp->data);
temp = temp->next;
}
printf("NULL\n");
}

int main()
{
push(10);
push(20);
push(30);
printf("Linked List\n");
printList();
pop();
printf("After the pop, the new linked list\n");
printList();
pop();
printf("After the pop, the new linked list\n");
printList();

enqueue(10);
enqueue(20);
enqueue(30);
printf("Queue :");
printList();
dequeue();
printf("After dequeue the new Queue :");
printList();
dequeue();
printf("After dequeue the new Queue :");
printList();
return 0;
}
