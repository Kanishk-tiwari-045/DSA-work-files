// struct ListNode* oddEvenList(struct ListNode* head) {
//     if (head == NULL || head->next == NULL)
//         return head;
//     struct ListNode *odd = head;
//     struct ListNode *even = head->next;
//     struct ListNode *evenHead = even;
//     while (even != NULL && even->next != NULL) {
//         odd->next = even->next;
//         odd = odd->next;
//         even->next = odd->next;
//         even = even->next;
//     }
//     odd->next = evenHead;
//     struct ListNode *temp = head;
//     while (temp != NULL) {
//         printf("%d ", temp->val);
//         temp = temp->next;
//     }
//     printf("\n");
//     return head;
// }