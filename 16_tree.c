#include <stdio.h>
#include <stdlib.h>

struct node{
    char value;
    struct node *left;
    struct node *right;
};

struct node *CreateNode(char val){
    struct node *node = (struct node*)malloc(sizeof(struct node));
    node->value = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}


void inorder(struct node *root){         // L node R
    if(root == NULL){
        return;
    }
    inorder(root->left);
    printf("%c ",root->value);
    inorder(root->right);
}

void postorder(struct node *root){         // L node R
    if(root == NULL){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    printf("%c ",root->value);
}

void preorder(struct node *root){         // L node R
    if(root == NULL){
        return;
    }
    printf("%c ",root->value);
    preorder(root->left);
    preorder(root->right);
}

int main(){
    printf("Binary Tree:\n");
    struct node *root;
    root = CreateNode('A');
    root->left = CreateNode('B');
    root->right = CreateNode('C');
    root->left->left = CreateNode('D');
    root->left->right = CreateNode('E');
    root->left->left->left= CreateNode('G');
    root->left->left->right = CreateNode('H');
    root->left->left->right->right = CreateNode('L');
    root->right->right = CreateNode('F');
    root->right->right->left = CreateNode('I');
    root->right->right->right = CreateNode('J');
    root->right->right->right->right = CreateNode('K');

    printf("Inorder:\n");
    inorder(root);
    printf("\nPostorder:\n");
    postorder(root);
    printf("\nPreorder:\n");
    preorder(root);
    return 0;
}

