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
    string alienOrder(vector<string>& words) {
        unordered_set<char> allchar;
        for(string& w : words)
        {
        	for(char ch : w)
        		allchar.insert(ch);
        }//记下所有的字符
        unordered_map<char,int> indegree;
        unordered_map<char,unordered_set<char>> graph;
        int n1, n2, n;
        for(int i = 1, j; i < words.size(); ++i)
        {
        	if(words[i-1] == words[i])
        		continue;
        	n1 = words[i-1].size();
        	n2 = words[i].size();
        	n = min(n1, n2);
        	for(j = 0; j < n; ++j)
        	{
        		if(words[i-1][j] != words[i][j])
        		{	//不相等的第一个构成有向图的边
        			graph[words[i-1][j]].insert(words[i][j]);
        			indegree[words[i][j]]++;
        			indegree[words[i-1][j]] += 0;
        			break;
        		}
        	}
        	if(j == n && n1 > n2)
        		return "";//前面相等，前者长不行
        }
        queue<char> q;
        for(auto it = indegree.begin(); it != indegree.end(); ++it)
        {
        	if(it->second == 0)
        		q.push(it->first);
        }
        string ans;
        while(!q.empty())
        {
        	char ch = q.front();
        	allchar.erase(ch);
        	q.pop();
        	ans += ch;
        	for(auto it = graph[ch].begin(); it != graph[ch].end(); ++it)
        	{
        		if(--indegree[*it] == 0)
        			q.push(*it);
        	}
        }
        if(ans.size() != indegree.size())
        	return "";
        while(allchar.size())
        {
        	ans += *allchar.begin();
        	allchar.erase(allchar.begin());
        }
        return ans;
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
//    s.maxProbability(3,v5,v1,0,2);
    s.alienOrder(st1);
    string s1 = "1";
    cout << s1[1] << "s[1]" << endl;
    TreeNode *t1 = new TreeNode(1);
    TreeNode *t2 = new TreeNode(2);
    TreeNode *t3 = new TreeNode(3);
    TreeNode *t4 = new TreeNode(4);
    TreeNode *t5 = new TreeNode(5);
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