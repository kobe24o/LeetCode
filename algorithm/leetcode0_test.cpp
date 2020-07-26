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
    int m, n;
    int longest = 1;
    vector<vector<int>> dir = {{-1,0},{1,0},{0,1},{0,-1}};
public:
    int longestIncreasingPath(vector<vector<int>>& mat) {
        if(mat.empty() || mat[0].empty())
            return 0;
        m = mat.size(), n = mat[0].size();
        vector<vector<int>> s(m, vector<int>(n,0));
        for(int i = 0, j; i < m; ++i)
            for(j = 0; j < n; ++j)
            {
                // if(s[i][j] != 0)
                // 	continue;
                longest = max(longest, dfs(0,0,mat,s));
            }
        return longest;
    }
    int dfs(int i, int j, vector<vector<int>>& mat, vector<vector<int>>& s)
    {
        if(s[i][j] != 0)
            return s[i][j];
        int x, y, k, longestpathofnext = 0;
        for(k = 0; k < 4; ++k)
        {
            x = i + dir[k][0];
            y = j + dir[k][1];
            if(x>=0 && x<m && y>=0 && y<n && mat[i][j] > mat[x][y])
            {
                longestpathofnext = max(longestpathofnext, dfs(x,y,mat,s));
            }
        }
        return s[i][j] = 1+longestpathofnext;
    }
};
void printv(vector<int>& v)
{
    for(auto& vi : v)
        cout << vi << " ";
    cout << endl;
}
int main() {
    vector<vector<int>> v6 ={{3,4,5},{3,2,6},{2,2,1}};
    vector<vector<int>> v5 ={{3, 0, 1, 4, 2},
                             {5, 6, 3, 2, 1},
                             {1, 2, 0, 1, 5},{4, 1, 0, 1, 7},
                             {1, 0, 3, 0, 5}};
    vector<double> v1 = {0.5,0.5,0.2};
    vector<int> v2 = {1,2,3,2,1};
    vector<int> v3 = {332484035, 524908576, 855865114, 632922376, 222257295, 690155293, 112677673, 679580077, 337406589, 290818316, 877337160, 901728858, 679284947, 688210097, 692137887, 718203285, 629455728, 941802184};
    vector<int> v4 = {1,3,2};
    string str = "eceeeefasdghjklqwertyuio";
    vector<vector<string>> st  = {{"A","B"},{"C"},{"B","C"},{"D"}};
    vector<string> st1 = {"za","zb","ca","cb"};

    Solution s;
    s.longestIncreasingPath(v6);



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