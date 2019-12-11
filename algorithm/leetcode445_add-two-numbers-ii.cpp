class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        string n1, n2, s;
        //链表转字符串
        while(l1 && l2)
        {
            n1.push_back(l1->val+'0');
            l1 = l1->next;
            n2.push_back(l2->val+'0');
            l2 = l2->next;
        }
        if(l1)
            while(l1)
            {
                n1.push_back(l1->val+'0');
                l1 = l1->next;
                n2.insert(0,"0");
            }
        if(l2)
            while(l2)
            {
                n2.push_back(l2->val+'0');
                l2 = l2->next;
                n1.insert(0,"0");
            }
        //字符串大数加法
        int i, bit, carry = 0, sum;
        for(i = n1.size()-1; i >= 0; --i)
        {
            sum = n1[i]-'0'+n2[i]-'0'+carry;
            bit = sum%10;
            carry = sum/10;
            s.push_back(bit+'0');
        }
        if(carry)
            s.push_back(carry+'0');
        ListNode *head = NULL, *node;
        for(i = 0; i < s.size(); ++i)
        {
            node = new ListNode(s[i]-'0');
            node->next = head;
            head = node;
        }
        return head;
    }
};