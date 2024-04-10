// struct ListNode* reverseBetween(struct ListNode* head, int left, int right) {
//     if (head == NULL || left == right) 
//         return head;
//     struct ListNode *curr = head;
//     struct ListNode *prev = NULL;
//     struct ListNode *ftr = NULL;
//     for (int i=1;i<left;i++) {
//         prev=curr;
//         curr=curr->next;
//     }
//     struct ListNode *leftPtr = prev; 
//     struct ListNode *rightPtr = curr; 
//     for (int i=left;i<=right;i++) {
//         ftr=curr->next;
//         curr->next=prev;
//         prev=curr;
//         curr=ftr;
//     }
//     if (leftPtr != NULL)
//         leftPtr->next=prev;
//     else
//         head=prev; 
//     rightPtr->next=curr;
//     return head;
// }