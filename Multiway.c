#include <stdio.h>
#include <stdlib.h>
#define n 5
struct mult_node{
    int count;
    int arr[n];
    struct mult_node *link[n];
};

void init(struct mult_node *node){
    node->count = 0;
    for(int i = 0; i < n; i++){
        node->link[i] = NULL;
    }
}

void swap(int *p,int *q){
    int t = *p;
    *p = *q;
    *q = t;
}

void bsort(struct mult_node* node){
    for(int i = 0; i < node->count-1; i++){
        for(int j = 0; j < node->count-i-1; j++){
            if (node->arr[j] > node->arr[j+1]){
                swap(&node->arr[j], &node->arr[j+1]);
            }
        } 
    }
}

void insert(struct mult_node *node, int x){
    if (node->count < n - 1){
        node->arr[node->count++] = x;
        bsort(node);
    }
    else{
        if (x <= node->arr[0]){
            if (node->link[0] == NULL){
                node->link[0] = (struct mult_node*)malloc(sizeof(struct mult_node));
                init(node->link[0]);
            }
            insert(node->link[0], x);
        }
        else if(x >= node->arr[n-2]){
            if (node->link[n - 1] == NULL){
                node->link[n - 1] = (struct mult_node*)malloc(sizeof(struct mult_node));
                init(node->link[n - 1]);
            }
            insert(node->link[n - 1], x);
        }
        else{
            for(int i = 1; i < n - 1; i++){
                if (x >= node->arr[i-1] && x <= node->arr[i]){
                    if (node->link[i] == NULL){
                        node->link[i] = (struct mult_node*)malloc(sizeof(struct mult_node));
                        init(node->link[i]);
                    }
                    insert(node->link[i], x);
                    break;
                }
            }
        }
    }
}

void display(struct mult_node *node){
    if(node != NULL){
        // printf("o\n");
        for(int i = 0; i < node->count; i++){
            printf("%d ", node->arr[i]);
        }
        printf("\n");
    }
    for(int j = 0; j < n; j++){
        printf("\n");
        if (node->link[j]!=NULL){
            display(node->link[j]);
        }
    }
}

int main(){
    struct mult_node *root = (struct mult_node*)malloc(sizeof(struct mult_node));
    init(root);
    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert\n");
        printf("2. Display\n");
        printf("3. Exit\n");

        int choice;
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                int x;
                printf("Enter the data: ");
                scanf("%d", &x);
                insert(root, x);
                printf("Data '%d' - inserted.\n", x);
                break;
            }

            case 2: {
                display(root);
                break;
            }

            case 3:
                printf("Exiting the program.\n");
                return 0;

            default:
                printf("Invalid choice. Please enter 1, 2, or 3.\n");
                break;
        }
    }
    return 0;
}