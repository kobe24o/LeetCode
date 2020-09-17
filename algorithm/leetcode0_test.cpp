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
    double soupServings(int N) {
        unordered_map<int,unordered_map<int,double>> dp, temp;
        dp[N][N] = 1.0;
        double prob = 0.0, p, pp;
        vector<vector<int>> delta = {{100,0},{75,25},{50,50},{25,75}};
        int A, B, nA, nB, i, idx;
        for(auto& item1 : dp)
        {
            A = item1.first;
            for(auto& item2 : item1.second)
            {
                B = item2.first;
                p = item2.second;
                if(A == 0)
                {
                    if(B == 0)
                        prob += p/2.0;
                    else if(B > 0)
                        prob += p;
                }
                else
                {
                    if(B == 0)
                        continue;
                    for(i = 0; i < 4; i++)
                    {
                        nA = max(0, A-delta[i][0]);
                        nB = max(0, B-delta[i][1]);
                        temp[nA][nB] += p*0.25;
                    }
                    dp.swap(temp);
                    temp.clear();
                }
            }
        }
        return prob;
    }
};
void printv(vector<int>& v)
{
    for(auto& vi : v)
        cout << vi << " ";
    cout << endl;
}
int main() {
    vector<vector<char>> v6 ={{'d','b','b'},{'c','a','a'},{'b','a','c'},{'c','c','c'},{'d','d','a'}};
    vector<vector<int>> v5 ={{1,1,1},{7,7,7},{7,7,7}};
    vector<double> v1 = {0.5,0.5,0.2};
    vector<int> v2 = {6,2,4};
    vector<int> v3 = {332484035, 524908576, 855865114, 632922376, 222257295, 690155293, 112677673, 679580077, 337406589, 290818316, 877337160, 901728858, 679284947, 688210097, 692137887, 718203285, 629455728, 941802184};
    vector<int> v4 = {1,3,2};
    string str = "eceeeefasdghjklqwertyuio";
    vector<vector<string>> st  = {{"A","B"},{"C"},{"B","C"},{"D"}};
    vector<string> st1 = {"0.700","2.800","4.900"};

    Solution s;
    s.soupServings(1);



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