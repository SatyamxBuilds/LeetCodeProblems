typedef struct Node
{
    int key;
    int index;
    struct Node *next;
} Node;

int* twoSum(int* nums, int numsSize, int target, int* returnSize)
{
    const int HASH_SIZE = 16384;      // Power of 2
    Node* table[16384] = {0};

    for(int i = 0; i < numsSize; i++)
    {
        int complement = target - nums[i];

        unsigned int hash = ((unsigned int)complement) & (HASH_SIZE - 1);

        Node *cur = table[hash];

        while(cur)
        {
            if(cur->key == complement)
            {
                int *ans = (int*)malloc(sizeof(int) * 2);
                ans[0] = cur->index;
                ans[1] = i;
                *returnSize = 2;
                return ans;
            }
            cur = cur->next;
        }

        hash = ((unsigned int)nums[i]) & (HASH_SIZE - 1);

        Node *node = (Node*)malloc(sizeof(Node));
        node->key = nums[i];
        node->index = i;
        node->next = table[hash];
        table[hash] = node;
    }

    *returnSize = 0;
    return NULL;
}