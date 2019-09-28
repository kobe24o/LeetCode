#include<string>
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
    	ListNode *emptyHead = new ListNode(-1);
    	emptyHead->next = head;
        ListNode *leftend = emptyHead, *rightstart = emptyHead;
        ListNode *revStart, *revEnd;
        while(--m)
        	leftend = leftend->next;
        revStart = leftend->next;
        leftend->next = NULL;
        while(n--)
        	rightstart = rightstart->next;
        revEnd = rightstart;
        rightstart = rightstart->next;
        revEnd->next = NULL;
        leftend->next = reverseList(revStart);
        revStart->next = rightstart;
        return emptyHead->next;
    }

    ListNode* reverseList(ListNode* head)
    {
    	ListNode *tempH = head;
    	if(!tempH || !tempH->next)
    		return tempH;
    	ListNode *prev = NULL, *nexNode;
    	while(tempH)
    	{
    		nexNode = tempH->next;
    		tempH->next = prev;
    		prev = tempH;
    		tempH = nexNode;
    	}
    	return prev->next;
    }
};

int main()
{
	ListNode *head = new ListNode(1);
	ListNode *h2 = new ListNode(2);
	ListNode *h3 = new ListNode(3);
	ListNode *h4 = new ListNode(4);
	ListNode *h5 = new ListNode(5);
	head->next = h2;
	h2->next = h3;
	h3->next = h4;
	h4->next = h5;
	Solution s;
	s.reverseBetween(head,2,4);
}