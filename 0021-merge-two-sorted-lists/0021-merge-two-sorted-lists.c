struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    struct ListNode* head = NULL;
    struct ListNode** tail = &head;

    while (list1 && list2) {
        if (list1->val <= list2->val) {
            *tail = list1;
            list1 = list1->next;
        } else {
            *tail = list2;
            list2 = list2->next;
        }
        tail = &((*tail)->next);
    }

    *tail = list1 ? list1 : list2;
    return head;
}