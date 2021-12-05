#include <bits/stdc++.h>
#include<vector>
#include<iostream>

using namespace std;


struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode *deleteMiddle(ListNode *head) {
        if (!head || !head->next) return NULL;
        ListNode *empty = new ListNode(0, head);
        ListNode *fast = empty, *slow = empty;
        while (fast && fast->next);
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        slow->next = slow->next->next;
        return empty->next;
    }
};

int main() {

    Solution s;
    vector<int> nums1 = {1,3,4,7,1,2,6};
    ListNode *head = new ListNode(1), *cur = head;
    for(int i = 1; i < nums1.size(); ++i)
    {
        cur->next = new ListNode(nums1[i]);
        cur = cur->next;
    }
    s.deleteMiddle(head);
    return 0;
}