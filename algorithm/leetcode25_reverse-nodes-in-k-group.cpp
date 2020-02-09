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
        //start，end，对应k个节点的首尾，prev前一段的末尾
        ListNode *temp=NULL;
        bool flag = false;
        int count;
        while(end)
        {
            count = k;
            start = prev->next;//前一段的下一个为start
            while(end && count)//end移动k次到末尾
            {
                end = end->next;
                count--;
            }
            if(!end)//如果end为空，说明，不够k个
                flag = true;//这一段不足k个，提前结束了
            else//够k个，需要反转
            {
                temp = end->next;//temp为下次反转的段的开头
                end->next = NULL;//断开与下段的链接
            }
            if(!flag)//没有提前结束，这段够k个，进行反转
            {
                prev->next = reverseList(start);
                //前一段的next接上新的头
                start->next = temp;
                //原来的头start变成尾巴，接上下一段的头temp
                prev = start;//更新prev为反转好的尾巴start
                end = start;//反转k个后，原来的end不是结尾了，end更新为新的结尾start
            }
        }
        return emptyHead->next;
    }

    ListNode* reverseList(ListNode *head)
    {   //反转链表，返回新的头结点
        ListNode *prev = NULL, *nt = head->next;
        while(head && head->next)
        {
            head->next = prev;
            prev = head;
            head = nt;
            nt = nt->next;
        }
        head->next = prev;
        return head;
    }
};