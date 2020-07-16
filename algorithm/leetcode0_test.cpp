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

class trie
{
public:
    trie* next[26] = {NULL};
    bool isend =  false;
    int count = 0;
    void insert(string& s)
    {
        trie* cur = this;
        for(int i = 0; i < s.size(); i++)
        {
            if(cur->next[s[i]-'a'] == NULL)
                cur->next[s[i]-'a'] = new trie();
            cur = cur->next[s[i]-'a'];
        }
        cur->count++;
        cur->isend = true;
    }
};
class dsu
{
public:
    vector<int> f;
    dsu(int n)
    {
        f.resize(n);
        for(int i = 0; i < n; ++i)
            f[i] = i;
    }
    void merge(int a, int b)
    {
        int fa = find(a);
        int fb = find(b);
        f[fa] = fb;
    }
    int find(int a)
    {
        int origin = a;
        while(a != f[a])
            a = f[a];
        return f[origin] = a;
    }
    int countUni(vector<vector<int>> &positions, int stop, vector<vector<int>> &grid, int n)
    {
        int count = 0, x, y, pos;
        for(int i = 0; i <= stop; ++i)
        {
            x = positions[i][0], y = positions[i][1];
            pos = x*n+y;
            if(pos == find(pos))
                count++;
        }
        return count;
    }
};

class Solution {
public:
    string nextClosestTime(string time) {
        set<int> s;
        s.insert(time[0]-'0');
        s.insert(time[1]-'0');
        s.insert(time[3]-'0');
        s.insert(time[4]-'0');
        if(s.size()==1) return time;//数字都一样
        vector<int> num(s.begin(),s.end());
        int i, j, h, m, size = num.size();
        int hour = (time[0]-'0')*10+time[1]-'0';
        int minute = (time[3]-'0')*10+time[4]-'0';
        int minlargeH = 24, minlargeM = 60;
        int minH = 24, minM = 60;
        for(i = 0; i < size; i++)
        {
            h = num[i];
            m = num[i];
            for(j = 0; j < size; j++)
            {
                h = h*10+num[j];
                m = m*10+num[j];
                minH = min(minH, h);
                minM = min(minM, m);
                if(h > hour && h < minlargeH)
                    minlargeH = h;
                if(m > minute && m < minlargeM)
                    minlargeM = m;
            }
        }
        if(minlargeM != 60)
            return time.substr(0,3)+ (minlargeM>10 ? to_string(minlargeM) : "0"+to_string(minlargeM));
        if(minlargeH != 24)
            return (minlargeH>10? to_string(minlargeH) : "0"+to_string(minlargeH)) + ":" + (minM>10? to_string(minM) : "0"+to_string(minM));
        return (minH>10? to_string(minH) : "0"+to_string(minH)) + ":" + (minM>10? to_string(minM): "0"+to_string(minM));
    }
};
void printv(vector<int>& v)
{
    for(auto& vi : v)
        cout << vi << " ";
    cout << endl;
}
int main() {
    vector<vector<int>> v6 ={{1,1},{3,3}};
    vector<vector<int>> v5 ={{0,1},{1,2},{0,2}};
    vector<double> v1 = {0.5,0.5,0.2};
    vector<int> v2 = {1,1,1,9,7};
    vector<int> v3 = {332484035, 524908576, 855865114, 632922376, 222257295, 690155293, 112677673, 679580077, 337406589, 290818316, 877337160, 901728858, 679284947, 688210097, 692137887, 718203285, 629455728, 941802184};
    vector<int> v4 = {1,3,2};
    string str = "eceeeefasdghjklqwertyuio";
    vector<vector<string>> st  = {{"A","B"},{"C"},{"B","C"},{"D"}};
    vector<string> st1 = {"za","zb","ca","cb"};
    Solution s;
    s.nextClosestTime("19:34");



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