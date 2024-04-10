// /**
//  * Definition for a binary tree node.
//  * struct TreeNode {
//  *     int val;
//  *     struct TreeNode *left;
//  *     struct TreeNode *right;
//  * };
//  */
// /**
//  * Note: The returned array must be malloced, assume caller calls free().
//  */
// int* preorderTraversal(struct TreeNode* root, int* returnsize) {
//     *returnsize = 0;
//     int* arr = malloc(100 * sizeof(int));
//     preorder(root, arr, returnsize);
//     return arr;
// }

// void preorder(struct TreeNode* root, int* arr, int* returnsize) {
//     if (root == NULL)
//         return;
//     arr[(*returnsize)++] = root->val;
//     preorder(root->left, arr, returnsize);
//     preorder(root->right, arr, returnsize);
// }
