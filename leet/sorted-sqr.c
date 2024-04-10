// int* sortedSquares(int* nums, int numsSize, int* returnSize) {
//     *returnSize = numsSize;
//     int* res = (int*)malloc(numsSize * sizeof(int));
//     if (res == NULL) {
//         return NULL;
//     }
//     int index=0;
//     for (int i = 0; i < numsSize; i++) {
//         nums[i] = nums[i] * nums[i];
//         res[index++] = nums[i];
//     }
//     for(int i = 0 ; i<numsSize ; i++){
//         for(int j = 0; j<numsSize-i-1 ; j++){
//             if(res[j+1] < res[j]){
//                 int temp = res[j];
//                 res[j] = res[j+1];
//                 res[j+1] = temp;
//             }
//         }
//     }
//     return res;
// }