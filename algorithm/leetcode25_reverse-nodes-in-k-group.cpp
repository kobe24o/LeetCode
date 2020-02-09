class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(k == 1 || !head)
            return head;
        int len = 1, count;
        ListNode *prev = NULL, *cur = head, *nt = head->next;
        ListNode *H = reverseList(prev,cur,len);
        if(len == 1)
            return head;
        count = len/k;
        len = len%k;//反转后，前几个(原末尾)不用反转的
        bool flag = (len == 0);
        prev = NULL, cur = H, nt = cur->next;
        while(len--)
        {
            prev = cur;
            cur = cur->next;
            if(cur)
                nt = cur->next;
        }
        if(prev)
            prev->next = NULL;
        ListNode *newhead;
        while(count--)
        {
            newhead = reverseKNode(cur,nt,k);//反转k个, cur是引用
            if(flag)
            {
                H = newhead;
                flag = false;
            }
            if(prev)
                prev->next = newhead;
            prev = cur;
            cur = nt;
            if(cur)
                nt = cur->next;
        }
        cur = H, prev = NULL;
        return reverseList(prev,cur,len);
    }

    ListNode* reverseList(ListNode *prev, ListNode *head, int& len)
    {
        ListNode *nt = head->next;
        while(head && head->next)
        {
            len++;
            head->next = prev;
            prev = head;
            head = nt;
            if(nt)
                nt = nt->next;
        }
        head->next = prev;
        return head;
    }

    ListNode* reverseKNode(ListNode* &head, ListNode* &nt, int k)
    {
        ListNode *prev = NULL, *tail = head;
        while(k--)
        {
            head->next = prev;
            prev = head;
            head = nt;
            if(nt)
                nt = nt->next;
        }
        nt = head;
        head = tail;
        return prev;
    }
};

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *emptyHead = new ListNode(-1);
        emptyHead->next = head;
        ListNode *prev = emptyHead, *start = emptyHead->next, *end = emptyHead;
        ListNode *temp=NULL;
        bool flag = false;
        int count;
        while(end)
        {
            count = k;
            start = prev->next;
            while(end && count)
            {
                end = end->next;
                count--;
            }
            if(!end)//
                flag = true;//这一段不足k个，提前结束了,allEnd是结尾
            else
            {
                temp = end->next;
                end->next = NULL;
            }
            if(!flag)
            {
                prev->next = reverseList(start);
                start->next = temp;
                prev = start;
                end = start;
            }
        }
        return emptyHead->next;
    }

    ListNode* reverseList(ListNode *head)
    {
        ListNode *prev = NULL, *nt = head->next;
        while(head && head->next)
        {
            head->next = prev;
            prev = head;
            head = nt;
            if(nt)
                nt = nt->next;
        }
        head->next = prev;
        return head;
    }
};