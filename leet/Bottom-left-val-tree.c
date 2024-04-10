// int findBottomLeftValue(struct TreeNode* root) {
//     if (root==NULL){
//         return -1;
//     }
//     struct TreeNode* que[10000];
//     int f1=0;
//     int r1=0;
//     int left;
//     que[r1++]=root;
//     while(f1<r1){
//         int level=r1-f1;
//         left=que[f1]->val;
//         for(int i=0;i<level;i++){
//             struct TreeNode* cur=que[f1++];
//             if(cur->left!=NULL){
//                 que[r1]=cur->left;
//                 r1++;
//             }
//             if(cur->right!=NULL){
//                 que[r1]=cur->right;
//                 r1++;
//             }  
//         }
//     }
//     return left;
// }