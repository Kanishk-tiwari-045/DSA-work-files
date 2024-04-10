/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
// struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
//     if (head == NULL) {
//         return head;
//     }
//     struct ListNode *pptr = head;
//     struct ListNode *ptr = head;
//     for (int i = 0; i < n; i++) {
//         if (pptr == NULL) {
//             return head;
//         }
//         pptr = pptr->next;
//     }
//     if (pptr == NULL) {
//         head = head->next;
//         free(ptr);
//         return head;
//     }
//     while (pptr->next != NULL) {
//         pptr = pptr->next;
//         ptr = ptr->next;
//     }
//     struct ListNode *temp = ptr->next;
//     ptr->next = temp->next;
//     free(temp);
//     return head;
// }
