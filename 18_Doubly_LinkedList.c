#include <stdio.h>
#include <stdlib.h>

struct DblNode {
    int data;
    struct DblNode* next;
    struct DblNode* prev;
};

struct DblNode* head = NULL;

// Function to insert at the beginning of the list
void insertAtFirstNode(int val) {
    struct DblNode* ptr = (struct DblNode*)malloc(sizeof(struct DblNode));
    if (ptr == NULL) {
        printf("Overflow!\n");
        return;
    }
    ptr->data = val;
    ptr->prev = NULL;

    if (head == NULL) {
        ptr->next = NULL;
        head = ptr;
    } else {
        ptr->next = head;
        head->prev = ptr;
        head = ptr;
    }
}

// Function to insert at the end of the list
void insertionAtLastDbly(int val) {
    struct DblNode* ptr = (struct DblNode*)malloc(sizeof(struct DblNode));
    if (ptr == NULL) {
        printf("Overflow!\n");
        return;
    }
    if (head == NULL) {
        insertAtFirstNode(val); // call insert first
    } else {
        ptr->data = val;
        ptr->next = NULL;

        struct DblNode* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = ptr;
        ptr->prev = temp;
    }
}

// Function to insert before a specific value
void insertBeforeBubly(int val1, int val2) {
    struct DblNode* ptr = (struct DblNode*)malloc(sizeof(struct DblNode));
    if (ptr == NULL) {
        printf("Overflow\n");
        return;
    }

    struct DblNode* temp = head;
    struct DblNode* last = NULL;

    while (temp != NULL && temp->data != val1) {
        last = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        free(ptr);
        printf("Value %d not found in the list. Can't insert before.\n", val1);
        return;
    }

    ptr->data = val2;
    ptr->next = temp;
    ptr->prev = last;
    temp->prev = ptr;

    if (last == NULL) {
        head = ptr;
    } else {
        last->next = ptr;
    }
}

// Function to insert after a specific value
void insertAfterValue(int val1, int val2) {
    struct DblNode* ptr = (struct DblNode*)malloc(sizeof(struct DblNode));
    if (ptr == NULL) {
        printf("Overflow\n");
        return;
    }

    struct DblNode* temp = head;

    while (temp != NULL && temp->data != val1) {
        temp = temp->next;
    }

    if (temp == NULL) {
        free(ptr);
        printf("Value %d not found in the list. Can't insert after.\n", val1);
        return;
    }

    ptr->data = val2;
    ptr->next = temp->next;
    if (temp->next != NULL) {
        temp->next->prev = ptr;
    }
    ptr->prev = temp;
    temp->next = ptr;
}

// Function to delete at the last node
void deleteAtLast() {
    if (head == NULL) {
        printf("No value to delete (list is empty).\n");
        return;
    } else if (head->next == NULL) {
        printf("Value in deleted node: %d\n", head->data);
        free(head);
        head = NULL;
    } else {
        struct DblNode* temp = head;
        while (temp->next->next != NULL) {
            temp = temp->next;
        }
        printf("Value in deleted node: %d\n", temp->next->data);
        free(temp->next);
        temp->next = NULL;
    }
}

// Function to delete before a specific value
void deleteBeforeValue(int val) {
    if (head == NULL || head->next == NULL) {
        printf("List is empty or has only one element. Cannot perform delete operation.\n");
        return;
    }

    struct DblNode* temp = head;

    if (temp->data == val) {
        printf("Cannot delete before the first element.\n");
        return;
    }

    while (temp->next != NULL && temp->next->data != val) {
        temp = temp->next;
    }

    if (temp->next == NULL || temp->next->prev == NULL) {
        printf("Value %d not found in the list or it's the first element. Cannot delete before.\n", val);
        return;
    }

    struct DblNode* nodeToDelete = temp->next->prev;
    temp->next->prev = nodeToDelete->prev;
    nodeToDelete->prev->next = temp->next;
    printf("Value in deleted node: %d\n", nodeToDelete->data);
    free(nodeToDelete);
}

// Function to delete after a specific value
void deleteAfterValue(int val) {
    if (head == NULL) {
        printf("List is empty. Cannot perform delete operation.\n");
        return;
    }

    struct DblNode* temp = head;

    while (temp != NULL && temp->data != val) {
        temp = temp->next;
    }

    if (temp == NULL || temp->next == NULL) {
        printf("Value %d not found in the list or it's the last element. Cannot delete after.\n", val);
        return;
    }

    struct DblNode* nodeToDelete = temp->next;
    temp->next = nodeToDelete->next;
    if (nodeToDelete->next != NULL) {
        nodeToDelete->next->prev = temp;
    }
    printf("Value in deleted node: %d\n", nodeToDelete->data);
    free(nodeToDelete);
}

// Function to display the doubly linked list
void DbDisplay() {
    struct DblNode* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Main function
int main() {
    insertAtFirstNode(11);
    insertAtFirstNode(12);
    insertAtFirstNode(13);
    insertAtFirstNode(14);
    insertAtFirstNode(15);
    insertAtFirstNode(16);
    insertionAtLastDbly(33);
    insertBeforeBubly(13, 55);
    insertAfterValue(12, 44);

    printf("Original List: ");
    DbDisplay();

    deleteAtLast();
    printf("\nList after deleting at last node: ");
    DbDisplay();

    deleteBeforeValue(33);
    printf("\nList after deleting before 33: ");
    DbDisplay();

    deleteAfterValue(12);
    printf("\nList after deleting after 12: ");
    DbDisplay();
}
