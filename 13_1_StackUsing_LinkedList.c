#include <stdio.h>
#include <stdlib.h>

struct node{
    int value;
    struct node* next;
};

struct node* top = NULL;
// struct node* first;

void enqueue(int n){
    struct node* ptr = (struct node*)malloc(sizeof(struct node)); 

    if(ptr == NULL){
        printf("Overflown\n");
        return;
    }
    if(top == NULL){
        ptr->value = n;
        ptr->next = NULL;
        top = ptr;

    }else{
        ptr->value = n;
        ptr->next = top;
        top = ptr;
    }
    printf("pushed %d\n",top->value);
}

void pop(){
    if(top == NULL){
        printf("Underflow\n");
        return;
    }
    struct node* temp1 = top;
    top = temp1->next;
    free(temp1);
}

void peek(){
    if(top == NULL){
        printf("Underflow\n");
        return;
    }
    printf("\nPeek value: %d\n",top->value);
}

void display(){
    struct node* current = top;
    while(current != NULL){
        printf("%d -> ",current->value);
        current = current->next;
    }
}

int main(){
    struct node *st;
    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);
    enqueue(5);
    enqueue(6);
    display();
    printf("\n");
    pop();
    display();
    peek();
    return 0;
}
