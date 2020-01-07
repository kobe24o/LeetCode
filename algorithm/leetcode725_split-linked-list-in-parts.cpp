class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* root, int k) {
        ListNode *cur = root, *temp;
        vector<ListNode*> ans(k, NULL);
        int len = 0, i = 0;
        while(cur)
        {
            len++;
            cur = cur->next;
        }

        int len2 = len/k, len1 = len/k;
        if(len%k)
            len1 += 1;
        int n1 = len - k * len2, j = 0, n;
        int n2 = k - n1;
        cur = root;
        while(n1--)
        {
            ans[i++] = cur;
            n = len1;
            while(--n)
                cur = cur->next;
            temp = cur->next;
            cur->next = NULL;
            cur = temp;
        }
        while(n2--)
        {
            ans[i++] = cur;
            n = len2;
            while(--n && cur)
                cur = cur->next;
            if(!cur)
                break;
            temp = cur->next;
            cur->next = NULL;
            cur = temp;
        }
        return ans;
    }
};