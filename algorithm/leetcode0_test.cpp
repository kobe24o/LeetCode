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

class LogSystem {
    vector<long long> second = {12*31*24*3600, 31*24*3600, 24*3600, 3600, 60, 1};
    map<string, int> unit = {{"Year",0},{"Month",1},{"Day",2},{"Hour",3},{"Minute",4},{"Second",5}};
    map<long long, int> m;
public:
    LogSystem() {

    }

    void put(int id, string timestamp) {
        m[timeToint(timestamp)] = id;
    }

    vector<int> retrieve(string s, string e, string gra) {
        long long start = timeToint(s, unit[gra]);
        long long end = timeToint(e, unit[gra], true);
        vector<int> ans;
        for(auto it = m.lower_bound(start); it != m.end(); ++it)
        {
            if(it->first > end)
                break;
            ans.push_back(it->second);
        }
        return ans;
    }
    long long timeToint(string& s, int g = 5, bool end = false)
    {	// 例如 2017:01:01:23:59:59
        long long Year = stoi(s.substr(0,4));
        long long Month = stoi(s.substr(5,2));
        long long Day = stoi(s.substr(8,2));
        long long Hour = stoi(s.substr(11,2));
        long long Minute = stoi(s.substr(14,2));
        long long Second = stoi(s.substr(17,2));
        long long t;
        if(g==5)
            t = (Year-1)*second[0]+(Month-1)*second[1]+(Day-1)*second[2]+(Hour-1)*second[3]+(Minute-1)*second[4]+(Second-1)*second[5];
        else if(g==4)
            t = (Year-1)*second[0]+(Month-1)*second[1]+(Day-1)*second[2]+(Hour-1)*second[3]+(Minute-1)*second[4];
        else if(g==3)
            t = (Year-1)*second[0]+(Month-1)*second[1]+(Day-1)*second[2]+(Hour-1)*second[3];
        else if(g==2)
            t = (Year-1)*second[0]+(Month-1)*second[1]+(Day-1)*second[2];
        else if(g==1)
            t = (Year-1)*second[0]+(Month-1)*second[1];
        else
            t = (Year-1)*second[0];
        t += end ? second[g] :0;
        return t;
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
    vector<vector<int>> v5 ={{3, 0, 1, 4, 2},
                             {5, 6, 3, 2, 1},
                             {1, 2, 0, 1, 5},{4, 1, 0, 1, 7},
                             {1, 0, 3, 0, 5}};
    vector<double> v1 = {0.5,0.5,0.2};
    vector<int> v2 = {1,1,1,9,7};
    vector<int> v3 = {332484035, 524908576, 855865114, 632922376, 222257295, 690155293, 112677673, 679580077, 337406589, 290818316, 877337160, 901728858, 679284947, 688210097, 692137887, 718203285, 629455728, 941802184};
    vector<int> v4 = {1,3,2};
    string str = "eceeeefasdghjklqwertyuio";
    vector<vector<string>> st  = {{"A","B"},{"C"},{"B","C"},{"D"}};
    vector<string> st1 = {"za","zb","ca","cb"};

    LogSystem l;
    l.put(1, "2017:01:01:23:59:59");
    l.put(2, "2017:01:01:22:59:59");
    l.put(3, "2016:01:01:00:00:00");
    l.retrieve("2016:01:01:01:01:01","2017:01:01:23:00:00","Year"); // 返回值 [1,2,3]，返回从 2016 年到 2017 年所有的日志。
    l.retrieve("2016:01:01:01:01:01","2017:01:01:23:00:00","Hour");



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