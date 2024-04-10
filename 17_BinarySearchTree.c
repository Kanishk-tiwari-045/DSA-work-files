#include <stdio.h>
#include <stdlib.h>

struct node{
    int val;
    struct node *left;
    struct node *right;
};

// Node creation 
struct node* createNode(int n){
    struct node *node = (struct node*)malloc(sizeof(struct node));
    node->val = n;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// node Insertion
struct node* insertNode(struct node* root,int n){
    if(root == NULL){
        return createNode(n);
    }
    if(n < root->val){
        root->left = insertNode(root->left,n);
    }else{
        root->right = insertNode(root->right,n);
    }
    return root;
}

// Inorder Traversal
struct node* inorder(struct node* root){
    
    if(root != NULL){
        inorder(root->left);
        printf("%d ",root->val);
        inorder(root->right);
    }
}

// post Order traversal

struct node* postOrder(struct node* root){
    if(root != NULL){
        printf("%d ",root->val);
        postOrder(root->left);
        postOrder(root->right);
    }
}
/*Can also be implemented as 
void inorder(struct node* root) {
    // ...
}
*/
// PreOrder traversal
struct node* preOrder(struct node* root){
    if(root != NULL){
        preOrder(root->left);
        preOrder(root->right);
        printf("%d ",root->val);
    }
}
// Searching a Key in tree
struct node* search(struct node* root,int target){
    if(root == NULL || root->val == target){
        return root;
    }
    if(target < root->val){
        return search(root->left,target);
    }
    return search(root->right,target);
}

// find Inorder predecessor
// struct node* InPre(struct node* root){
//     root = root->left;
//     while(root->right != NULL){
//         root = root->right;
//     }
//     return root;
// }
// deletion

struct node* InorderPost(struct node* root){
    root = root->right;
    while(root->left != NULL){
        root = root->left;
    }
    return root;
}

struct node *deleteNode(struct node* root,int value){
    // case1: No value in root
    if(root == NULL){
        return root;
    }
    // case2: No child
    if(root->left == NULL && root->right == NULL){
        free(root);
        return NULL;
    }
    
    // case3: having multiple childs
    struct node* reqNode;
    // search node to be deleted
    if(root->val > value){
        root->left = deleteNode(root->left,value);
    }else if(root->val < value){
        root->right = deleteNode(root->right,value);
    }

    // case4: Node is found and deletion takes place.
    else{
        reqNode = InorderPost(root);      // So, the first thing you would do here is to find the Inorder predecessor of the root node you want to delete and store it in a struct node pointer iPre. 
        root->val = reqNode->val;         // root value replaced by inorder predeseccor or sucsessor
        root->right = deleteNode(root->right,reqNode->val);     // know deleteing data on pointer reqNode by searching recursively. We search by root->right for succ.. and root->left for prede..
    } 
    return root;
}   
 

/* 
for using Inorder succsecsor 
        reqNode = InorderPost(root);      
        root->val = reqNode->val;
        root->right = deleteNode(root->right,reqNode->val);    
*/
//---And this function 

// https://www.codewithharry.com/videos/data-structures-and-algorithms-in-hindi-78/

int main(){
    struct node* Root = NULL;
    Root = insertNode(Root,5);
    Root = insertNode(Root,1);
    Root = insertNode(Root,3);
    Root = insertNode(Root,2);
    Root = insertNode(Root,5);
    Root = insertNode(Root,6);
    Root = insertNode(Root,8);
    printf("Inorder:");
    inorder(Root);
    printf("\nPost order:");
    postOrder(Root);
    printf("\nPre order:");
    preOrder(Root);


    if(search(Root,3) == NULL){
        printf("\nValue not found.\n");
    }else{
        printf("\nValue found.");
    }

    deleteNode(Root,5);
    printf("\nAfter deleting %d:",5);
    inorder(Root);
    return 0;
}