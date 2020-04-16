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
    bool isEnd = false;
    trie* next[26] = {NULL};
    void insert(string& s)
    {
        trie *cur = this;
        for(int i = 0; i < s.size(); ++i)
        {
            if(!cur->next[s[i]-'a'])
                cur->next[s[i]-'a'] = new trie();
            cur = cur->next[s[i]-'a'];
        }
        cur->isEnd = true;
    }
    bool find(string& s)
    {
        trie *cur = this;
        for(int i = 0; i < s.size(); ++i)
        {
            if(!cur->next[s[i]-'a'])
                return false;
            cur = cur->next[s[i]-'a'];
        }
        return cur->isEnd;
    }
};
class Solution {
    trie* t;
    vector<string> ans;
    vector<string> temp;
public:
    vector<string> maxRectangle(vector<string>& words) {
        t = new trie();
        vector<vector<string>> m(101);
        int maxlen = 0, maxarea = 0, area;
        for(auto w : words)
        {
            t->insert(w);
            m[w.size()].push_back(w);
            maxlen = max(maxlen, int(w.size()));
        }

        for(int i = 100; i >= 0; --i)
        {
            if(m[i].size()==0)
                continue;
            if(maxarea/(m[i][0].size()) >= maxlen)
                break;//最长的单词都不够
            temp.clear();
            area = 0;
            dfs(m[i],0,maxarea,area);
        }
        return ans;
    }

    void dfs(vector<string> &wd, int idx, int& maxarea, int area)
    {
        for(int i = 0; i < wd.size(); ++i)
        {
            temp.push_back(wd[i]);
            vector<bool> res = isgood(temp);
            if(res[0])//可以往下加单词
            {
                area = temp.size()*temp[0].size();
                if(res[1] && area > maxarea)//都是结束单词
                {
                    maxarea = area;
                    ans = temp;
                }
                dfs(wd, 0, maxarea, area);
            }
            else//不能加
                temp.pop_back();
        }
    }


    vector<bool> isgood(vector<string>& tp)
    {
        trie *cur;
        bool allend = true;
        int i, j, n = tp[0].size();
        for(j = 0; j < n; ++j)//按列在trie中检查
        {
            cur = t;
            for(i = 0; i < tp.size(); ++i)
            {
                if(!cur->next[tp[i][j]-'a'])
                    return {false, false};
                cur = cur->next[tp[i][j]-'a'];
            }
            allend &= cur->isEnd;
        }
        return {true, allend};
    }
};

//["01","10","0","1","1001010"] 9
//["01","0","0101010"]  6
//["011000","0111010","01101010"] 9
//["011000","0111011","01001010"] 11
//["01","1000000","11111111"] 13
//则当前节点所构成的最大距离即左深度+右深度-2*当前节点深度。

//["...1","..S.","..*.",".0.T"]   9
void printv(vector<int>& v)
{
    for(auto& vi : v)
        cout << vi << " ";
    cout << endl;
}
int main() {
//    vector<vector<int>> v6 = {{-13260,8589},{1350,8721},{-37222,-19547},{-54293,-29302},{-10489,-13241},{-19382,574},{5561,1033},{-22508,-13241},{-1542,20695},{9277,2820},{-32081,16145},{-50902,23701},{-8636,19504},{-17042,-28765},{-27132,-24156},{-48323,-4607},{30279,29922}};
    vector<vector<int>> v6 ={{1,1,1},{1,0,1},{1,1,1}};
    vector<int> v1 = {68,130,64};
    vector<int> v2 = {-230,194,7};
    vector<int> v3 = {-1,0};
    vector<int> v4 = {3,2};
    string str = "eceeeefasdghjklqwertyuio";
    vector<vector<int>> v5 = {{2,4,3},{6,5,2}};
    vector<string> st  = {"hjhbr", "dixpgflm", "jjzgr", "gb", "ruzih", "zvthz", "rcadj", "agched", "jwvouurr", "hpmyrbq", "rdzfv", "pdffy", "ihsvg", "dihvb", "fhdwixmy", "cpvhj", "x", "aotsh", "qgahgz", "upoij"};
    vector<string> st1 = {};
    Solution s;
    s.maxRectangle(st);
    printv(v4);

    string s1 = "1";
    cout << s1[1] << "s[1]" << endl;
    TreeNode *t1 = new TreeNode(0);
    TreeNode *t2 = new TreeNode(1);
    TreeNode *t3 = new TreeNode(2);
    TreeNode *t4 = new TreeNode(3);
    TreeNode *t5 = new TreeNode(4);
    t1->left = t2;
    t1->right = t3;
    t2->left = t4;
    t2->right = t5;


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
    vector<int> a = {1,2,3};
    cout << a.size() << endl;
    a.resize(a.size()+5);
    cout << a.size() << endl;
    for(int i = 0; i < 8; ++i)
        cout << a[i] << endl;
    return 0;
}