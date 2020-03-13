class node
{
public:
    int sum;
    int start, end;
    node *left, *right;
    node(int s, int e, int v):start(s),end(e),sum(v)
    {
        left = right = NULL;
    }

    static node* build(vector<int>& A, int l, int r)
    {
        if(l > r)
            return NULL;
        node* head = new node(l,r,A[l]);
        if(l == r)
            return head;
        int mid = l+((r-l)>>1);
        head->left = build(A,l,mid);
        head->right = build(A,mid+1,r);
        head->sum = 0;
        if(head->left)
            head->sum += head->left->sum;
        if(head->right)
            head->sum += head->right->sum;
        return head;
    }

    static long long query(node* head, int s, int e)
    {
        if(s > head->end || e < head->start)
            return 0;
        if(head->start >= s && head->end <= e)
            return head->sum;
        int vl = query(head->left, s, e);
        int vr = query(head->right,s, e);
        return vl+vr;
    }

    static void modify(node* head, int id, int val)
    {
        if(head->start == head->end)
        {
            head->sum = val;
            return;
        }
        int mid = (head->start + head->end)/2;
        if(id > mid)
            modify(head->right, id, val);
        else
            modify(head->left, id, val);
        head->sum = 0;
        if(head->left)
            head->sum += head->left->sum;
        if(head->right)
            head->sum += head->right->sum;
    }
};
class Solution {
    node *head;
public:
    Solution(vector<int> A) {
        head = node::build(A,0,A.size()-1);
    }

    long long query(int start, int end) {
        return node::query(head, start,end);
    }

    void modify(int index, int value) {
        node::modify(head, index,value);
    }
};