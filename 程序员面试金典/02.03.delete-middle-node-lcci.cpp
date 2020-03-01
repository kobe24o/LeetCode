class Solution {
public:
    void deleteNode(ListNode* node) {
        swap(node->val, node->next->val);
        node->next = node->next->next;
    }
};