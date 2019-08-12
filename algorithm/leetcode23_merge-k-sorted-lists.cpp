#include <queue>
#include <vector>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution
{
public:
    struct cmp
    {
        bool operator()(ListNode *a, ListNode *b)
        {
            return a->val > b->val;
        }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists)
    {
        priority_queue<ListNode*, vector<ListNode*>, cmp> queue;
        ListNode *head = new ListNode(0);
        ListNode *temp = head, *topNext;
        for(int i = 0; i < lists.size(); ++i)
        {
            if(lists[i])
                queue.push(lists[i]);
        }
        while(!queue.empty())
        {
            temp->next = new ListNode(queue.top()->val);
            temp = temp->next;
            topNext = queue.top()->next;
            queue.pop();
            if(topNext)
                queue.push(topNext);
        }
        return head->next;
    }
};