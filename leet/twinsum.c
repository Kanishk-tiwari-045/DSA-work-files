// void reverse(struct ListNode **head) {
//     struct ListNode *prev = NULL;
//     struct ListNode *current = *head;
//     struct ListNode *next = NULL;
//     while (current != NULL) {
//         next = current->next;
//         current->next = prev;
//         prev = current;
//         current = next;
//     }
//     *head = prev;
// }
// int pairSum(struct ListNode* head){
//     struct ListNode *temp=head;
//     int count=0;
//     while(temp->next!=NULL){
//         temp=temp->next;
//         count++;
//     }
//     struct ListNode *p1=head;
//     struct ListNode *p2=head;
//     for(int i=0;i<(count/2);i++){
//         p1=p1->next;
//         p2=p1;
//     }
//     p2=p2->next;
//     p1->next=NULL;  

//     reverse(&p2);
//     p1 = head;
//     int max=INT_MIN;
//     while(p1!=NULL && p2!=NULL){
//         if(max <  p1->val+p2->val){
//             max =  p1->val+p2->val;
//         }
//         p1=p1->next;
//         p2=p2->next;
//     }
//     return max;
// }