#include <stdio.h>
#include <stdlib.h>

struct Node {
int data;
struct Node* next;
struct Node* prev;
};

void insertFront(struct Node** head, int data) {

struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

newNode->data = data;

newNode->next = (*head);

newNode->prev = NULL;

if ((*head) != NULL)
(*head)->prev = newNode;

(*head) = newNode;
}

void insertAfter(struct Node* prev_node, int data) {

if (prev_node == NULL) {
printf("previous node cannot be null");
return;
}

struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

newNode->data = data;
// set next of newNode to next of previous node
newNode->next = prev_node->next;

prev_node->next = newNode;


newNode->prev = prev_node;
// set previous of newNode's next to newNode
if (newNode->next != NULL)
newNode->next->prev = newNode;
}

void insertEnd(struct Node** head, int data) {

struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

newNode->data = data;

newNode->next = NULL;

struct Node* temp = *head;
if (*head == NULL) {
newNode->prev = NULL;
*head = newNode;
return;
}
while (temp->next != NULL)
temp = temp->next;
temp->next = newNode;
newNode->prev = temp;
}

void deleteAtBeginning(struct Node** head)
{
// checking if the DLL is empty
if (*head == NULL) {
printf("The list is already empty.\n");
return;
}
struct Node* temp = *head;
*head = (*head)->next;
if (*head != NULL) {
(*head)->prev = NULL;
}
free(temp);
}


void deleteAtEnd(struct Node** head)
{
// checking if DLL is empty
if (*head == NULL) {
printf("The list is already empty.\n");
return;
}
struct Node* temp = *head;
if (temp->next == NULL) {
*head = NULL;
free(temp);
return;
}
while (temp->next != NULL) {
temp = temp->next;
}
temp->prev->next = NULL;
free(temp);
}

void deleteAtPosition(struct Node** head, int position)
{
if (*head == NULL) {
printf("The list is already empty.\n");
return;
}
struct Node* temp = *head;
if (position == 1) {
deleteAtBeginning(head);
return;
}
for (int i = 1; temp != NULL && i < position; i++) {
temp = temp->next;
}
if (temp == NULL) {
printf("Position is greater than the number of "
"nodes.\n");
return;
}
if (temp->next != NULL) {
temp->next->prev = temp->prev;
}
if (temp->prev != NULL) {
temp->prev->next = temp->next;
}
free(temp);
}


void displayList(struct Node* node) {
struct Node* last;
while (node != NULL) {
printf("%d->", node->data);
last = node;
node = node->next;
}
if (node == NULL)
printf("NULL\n");
}

int main() {
struct Node* head = NULL;
insertEnd(&head, 5);
insertFront(&head, 1);
insertFront(&head, 6);
insertEnd(&head, 9);
// insert 11 after head
insertAfter(head, 11);
// insert 15 after the seond node
insertAfter(head->next, 15);
displayList(head);
// delete the last node
deleteAtBeginning(&head);
displayList(head);
deleteAtEnd(&head);
displayList(head);
deleteAtPosition(&head,3);
displayList(head);
}
