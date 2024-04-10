#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *link;
};

struct Node* head = NULL;

void reverse(){
    struct Node *prev = NULL;
    struct Node *next = NULL;
    while(head != NULL){
        next = head->link;
        head->link = prev;
        prev = head;
        head = next;
    }
    head = prev;
}


void insertionAtFirst(int val){
    struct Node *ptr = (struct Node*)malloc(sizeof(struct Node));    // to create a memory address for new node to be assigned.
    if(ptr == NULL){
        printf("Overflown\n");
        return;
    }
    else{
        printf("Enter data value:");
        int val;
        scanf("%d",&val);
        ptr->data = val;
        ptr->link = head;
        head = ptr;
    }
}

void insertionAtLast(int val){
    struct Node *ptr = (struct Node*)malloc(sizeof(struct Node*));       
    if(ptr == NULL){
        printf("Overflown\n");
        return;
    }
    if(head == NULL){
        insertionAtFirst( val);        // call insert first
    }
    else{
        // printf("Enter last data value:");
        // int val;
        // scanf("%d",&val);
        ptr->data = val;
        ptr->link = NULL;

        struct Node *temp = head;
        while(temp->link != NULL){
            temp = temp->link;
        }
        temp->link = ptr;
    }
}

void insertBeforeValue(int val1, int val2) {
    struct Node* ptr = (struct Node*)malloc(sizeof(struct Node)); // Removed * in sizeof
    if (ptr == NULL) {
        printf("Overflow\n");
        return;
    }

    struct Node* temp = head;
    struct Node* prev = NULL;

    while (temp != NULL && temp->data != val1) {
        prev = temp;
        temp = temp->link;
    }

    if (temp == NULL) {
        free(ptr);
        printf("Value %d not found in the list. Can't insert before.\n", val1);
        return;
    }

    ptr->data = val2;
    ptr->link = temp;

    if (prev == NULL) {
        head = ptr;
    } else {
        prev->link = ptr;
    }
}

void insertAfterValue(int val1, int val2) {
    struct Node* ptr = (struct Node*)malloc(sizeof(struct Node)); // Removed * in sizeof
    if (ptr == NULL) {
        printf("Overflow\n");
        return;
    }

    struct Node* temp = head;

    while (temp != NULL && temp->data != val1) {
        temp = temp->link;
    }

    if (temp == NULL) {
        free(ptr);
        printf("Value %d not found in the list. Can't insert after.\n", val1);
        return;
    }

    ptr->data = val2;
    ptr->link = temp->link;
    temp->link = ptr;
}
void deleteAtFirst() {
    if (head == NULL) {
        printf("No value to delete (list is empty).\n");
        return;
    } else {
        struct Node* temp = head;
        head = head->link;
        printf("Value in deleted node: %d\n", temp->data);
        free(temp);
    }
}

void deleteAtLast(){
    if (head == NULL) {
        printf("No value\n");
        return;
    }
    if (head->link == NULL) {
        // There's only one node in the list, so delete it.
        free(head);
        head = NULL;
        return;
    }
    struct Node *temp = head;
    while(temp->link->link != NULL){
        temp = temp->link;
    }
    temp->link = NULL;
}

void deleteBeforeValue(int val) {
    if (head == NULL) {
        printf("List is empty, can't delete before.\n");
        return;
    }
    if (head->data == val) {
        printf("No node to delete before %d (head node).\n", val);
        return;
    }

    struct Node *temp = head;
    struct Node *prev = NULL;
    struct Node *prev2 = NULL;

    while (temp != NULL && temp->data != val) {
        prev2 = prev;
        prev = temp;
        temp = temp->link;
    }
    if (temp == NULL) {
        printf("Node with value %d not found in the list. Can't delete before.\n", val);
        return;
    }
    if (prev == head) {
        head = temp;
    } else {
        prev2->link = temp;
    }

    free(prev);
}

void Deletionafternode() {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }

    struct Node *ptr = head;
    struct Node *pptr = head;
    int z;
    printf("Enter the value after which to delete: ");
    scanf("%d", &z);

    while (pptr != NULL && pptr->data != z) {
        pptr = ptr;
        ptr = ptr->link;
    }

    if (pptr == NULL) {
        printf("Value %d not found in the list.\n");
        return;
    }
    if (ptr == head) {
        head = ptr->link;
    } else {
        pptr->link = ptr->link;
    }

    free(ptr);
}

void display(){
    struct Node* current = head;
    int i = 0;
    while(current != NULL){
        printf("%d -> ",current->data);
        i++;
        current = current->link;
    }printf("\n Total elements: %d\n",i);
}

    


int main() {
    insertionAtFirst(86);    // 86      f
    insertionAtFirst(75);    // 75 
    insertionAtFirst(10);    // 10
    insertionAtLast(17);    // 17        
    insertBeforeValue(17, 101); // Insert 101 before 17
    insertAfterValue(17, 207);  // Insert 207 after 17
    // deleteAtLast();
    // deleteAtFirst();
    display();
    printf("Head is %d\n",head->data);
    reverse();
    printf("\n");
    display();
    printf("Head is %d\n",head->data);
    return 0;
}