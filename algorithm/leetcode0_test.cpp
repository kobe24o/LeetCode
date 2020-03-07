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
unordered_map<int,int> m;// idx，能扔的dis
struct cmp
{
    bool operator()(const pair<int,int>& a, const pair<int,int>& b)
    {
        if(a.second == b.second)
            return m[a.first] < m[b.first];
        return a.second > b.second;
    }
};

class Solution {
public:
    /**
     * @param p: the position of the i-th stone
     * @param d: how far the stones can be stone
     * @return: the distance from the start point to the farthest stone.
     */
    int getDistance(vector<int> &p, vector<int> &d) {
        // Write your code here.
        if(p.size() == 0)
            return 0;
        bool flag = true;

        priority_queue<pair<int,int>,vector<pair<int,int>>,cmp> q;
        // idx, D距离

        for(int i = 0; i < p.size(); ++i)
        {
            m[i] = d[i];// idx，能扔的dis
            q.push(make_pair(i, q[i]));
        }

        pair<int,int> tp;
        while(!q.empty())
        {
            tp = q.top();
            q.pop();
            if(flag)
            {
                q.push(make_pair(tp.first, tp.second+m[tp.first]));
            }
            flag = !flag;
        }
        return tp.second;
    }
};



int main() {
    Solution s;

    vector<int> v = {1,6};
    vector<int> v1 = {5,6};
    string str = "eceeeefasdghjklqwertyuio";
    s.getDistance(v,v1);
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