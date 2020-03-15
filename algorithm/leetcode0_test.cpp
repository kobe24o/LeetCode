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
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
using namespace std;

class CustomStack {
    int s, v;
    int count = 0;
    deque<int> q;
    deque<int> q1;
public:
    CustomStack(int maxSize) {
        s = maxSize;
    }

    void push(int x) {
        if(count < s)
        {
            q.push_back(x);
            count++;
        }
    }

    int pop() {
        if(s==0)
            return -1;
        if(!q.empty())
        {
            v = q.back();
            q.pop_back();
            count--;
        }
        else
        {
            v = q1.back();
            q1.pop_back();
            count--;
        }
        return v;
    }

    void increment(int k, int val) {
        int t = min(k, count);
        k = t;
        t = t - q1.size();
        while(t>0)
        {
            v = q.front();
            q.pop_front();
            q1.push_back(v);
            t--;
        }
        t = k;
        while(t>0)
        {
            v = q1.front()+val;
            q1.pop_front();
            q1.push_back(v);
            t--;
        }
        while(k--)
        {
            q1.push_front(q1.back());
            q1.pop_back();
        }
    }
};

int main() {
    vector<vector<int>> v = {{1,3,2},{4,6,5},{7,9,8},{13,15,14},{10,12,11}};
    vector<int> v1 = {10,9,2,5,3,7,101,18};
    vector<int> v3 = {21,44,5,21,33,38,23,5,25,43};
    string str = "eceeeefasdghjklqwertyuio";
    vector<vector<int>> v2 = {{3,7,8},{9,11,13},{15,16,17}};

    CustomStack s(3);
    s.push(1);
    s.push(2);
    s.pop();
    s.push(2);
    s.push(3);
    s.push(4);
    s.increment(5,100);
    s.increment(2,100);
    s.pop();
    s.pop();
    s.pop();
    s.pop();

    TreeNode *t1 = new TreeNode(1);
    TreeNode *t2 = new TreeNode(2);
    TreeNode *t3 = new TreeNode(3);
    TreeNode *t4 = new TreeNode(4);
    t2->left = t1;
    t2->right = t3;
    t3->right = t4;


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