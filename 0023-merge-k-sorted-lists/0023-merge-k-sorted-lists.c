/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

static inline struct ListNode* merge(struct ListNode* a, struct ListNode* b)
{
    struct ListNode dummy;
    struct ListNode *tail = &dummy;

    while (a && b)
    {
        if (a->val <= b->val)
        {
            tail->next = a;
            a = a->next;
        }
        else
        {
            tail->next = b;
            b = b->next;
        }

        tail = tail->next;
    }

    tail->next = a ? a : b;

    return dummy.next;
}

struct ListNode* mergeKLists(struct ListNode** lists, int listsSize)
{
    if (listsSize == 0)
        return NULL;

    for (int step = 1; step < listsSize; step <<= 1)
    {
        for (int i = 0; i + step < listsSize; i += (step << 1))
        {
            lists[i] = merge(lists[i], lists[i + step]);
        }
    }

    return lists[0];
}