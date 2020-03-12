/**
 * @description: 调试使用
 * @author: michael ming
 * @date: 2019/11/24 22:55
 * @modified by: 
 */
#include <bits/stdc++.h>

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

using namespace std;
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
    /* you may need to use some attributes here */

    /*
    * @param A: An integer array
    */
    Solution(vector<int> A) {
        head = node::build(A,0,A.size()-1);
    }

    /*
     * @param start: An integer
     * @param end: An integer
     * @return: The sum from start to end
     */
    long long query(int start, int end) {
        return node::query(head, start,end);
    }

    /*
     * @param index: An integer
     * @param value: An integer
     * @return: nothing
     */
    void modify(int index, int value) {
        node::modify(head, index,value);
    }
};


int main() {
    vector<vector<int>> v = {{1,3,2},{4,6,5},{7,9,8},{13,15,14},{10,12,11}};
    vector<int> v1 = {1,2,7,8,5};
    string str = "eceeeefasdghjklqwertyuio";
    vector<vector<int>> v2 = {{2,1},{3,2}};//{4,2},{5,2},{6,5},{7,1},{8,3},{9,1},{10,1}};
    Solution s(v1);
    s.query(2,3);
    s.modify(0,4);
    s.query(0,1);
    s.modify(2,1);
    ListNode *h1 = new ListNode(3);
    ListNode *h2 = new ListNode(5);
    ListNode *h3 = new ListNode(8);
    ListNode *h4 = new ListNode(5);
    ListNode *h5 = new ListNode(10);
    ListNode *h6 = new ListNode(2);
    ListNode *h7 = new ListNode(1);
    h1->next = h2;
    h2->next = h3;
    h3->next = h4;
    h4->next = h5;
    h5->next = h6;
    h6->next = h7;
    return 0;
}