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
        ListNode *revStart, *revEnd;//需要反转的开始终点

        while(n--)//右边的先过去，不然左边断开了，过不去了
            rightstart = rightstart->next;
        revEnd = rightstart;
        rightstart = rightstart->next;
        revEnd->next = NULL;//断开需要反转的右端点

        while(--m)
            leftend = leftend->next;
        revStart = leftend->next;
        leftend->next = NULL;//断开需要反转的左端点

        reverseList(revStart, revEnd);//反转中间段
        leftend->next = revStart;
        revEnd->next = rightstart;
        return emptyHead->next;
    }

    void reverseList(ListNode* &head, ListNode* &tail)//传入的是引用
    {
        tail = head;//尾巴是现在的起点
        ListNode *tempH = head;
        if(!tempH || !tempH->next)
            return;
        ListNode *prev = NULL, *nexNode;
        while(tempH)
        {
            nexNode = tempH->next;
            tempH->next = prev;
            prev = tempH;
            tempH = nexNode;
        }
        head = prev;//起点是现在的尾巴
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