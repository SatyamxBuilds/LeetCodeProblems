struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode* head = NULL;
    struct ListNode** tail = &head;
    int carry = 0;

    while (l1 || l2 || carry) {
        int sum = carry;
        
        if (l1) {
            sum += l1->val;
            l1 = l1->next;
        }
        if (l2) {
            sum += l2->val;
            l2 = l2->next;
        }

        carry = sum / 10;
        
        struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
        newNode->val = sum % 10;
        newNode->next = NULL;

        *tail = newNode;
        tail = &((*tail)->next);
    }

    return head;
}