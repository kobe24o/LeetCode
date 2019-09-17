class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if(!head) return NULL;
        ListNode *slow, *slow_pre, *fast;
        slow = fast = head;
        slow_pre = NULL;
        while(fast && fast->next) 
        {
        	slow_pre = slow;
        	slow = slow->next;
        	fast = fast->next->next;
        }
        if(slow_pre)
        	slow_pre->next = NULL;//断开链表
        if(slow && slow != head)
        {
        	TreeNode *root = new TreeNode(slow->val);
        	root->left = sortedListToBST(head);
        	root->right = sortedListToBST(slow->next);
        	return root;
        }
        return new TreeNode(head->val);
    }
};