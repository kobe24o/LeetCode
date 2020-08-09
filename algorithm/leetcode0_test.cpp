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
    vector<vector<int>> candyCrush(vector<vector<int>>& b) {
    	bool todo = false;
    	int m = b.size(), n = b[0].size(), i, j, up, down;
    	for(i = 0; i < m; ++i)//横向检查
    		for(j = 0; j < n-2; ++j)
    		{
    			if(abs(b[i][j])==abs(b[i][j+1]) && abs(b[i][j+1])==abs(b[i][j+2]))
    			{
    				b[i][j] = b[i][j+1] = b[i][j+2] = -abs(b[i][j]);//标记为负的
    				todo = true;
    			}
    		}
    	for(j = 0; j < n; ++j)//纵向检查
    		for(i = 0; i < m-2; ++i)
    		{
    			if(abs(b[i][j])==abs(b[i+1][j]) && abs(b[i+1][j])==abs(b[i+2][j]))
    			{
    				b[i][j] = b[i+1][j] = b[i+2][j] = -abs(b[i][j]);//标记为负的
    				todo = true;
    			}
    		}
    	for(i = 0; i < m; ++i)//负的 标记为0要删除
    		for(j = 0; j < n; ++j)
    			if(b[i][j] < 0)
    				b[i][j] = 0;
    	for(j = 0; j < n; ++j)//纵向掉落
    	{
    		down = up = m-1;//从最底下开始往上找
    		while(down >= 0)
    		{	//双指针搬移数据
    			if(b[down][j] == 0)
    			{
    				up = down-1;
    				while(up >= 0 && b[up][j] == 0)
    					up--;
    				if(up >= 0)
    					swap(b[down][j], b[up][j]);
    				else
    					break;
    			}
    			down--;
    		}
    	}
    	if(todo)
    		candyCrush(b);
    	return b;
    }
};
void printv(vector<int>& v)
{
    for(auto& vi : v)
        cout << vi << " ";
    cout << endl;
}
int main() {
    vector<vector<int>> v6 ={{110,5,112,113,114},{210,211,5,213,214},{310,311,3,313,314},{410,411,412,5,414},{5,1,512,3,3},{610,4,1,613,614},{710,1,2,713,714},{810,1,2,1,1},{1,1,2,2,2},{4,1,4,4,1014}};
    vector<vector<int>> v5 ={{3, 0, 1, 4, 2},
                             {5, 6, 3, 2, 1},
                             {1, 2, 0, 1, 5},{4, 1, 0, 1, 7},
                             {1, 0, 3, 0, 5}};
    vector<double> v1 = {0.5,0.5,0.2};
    vector<int> v2 = {1,3,4,5};
    vector<int> v3 = {332484035, 524908576, 855865114, 632922376, 222257295, 690155293, 112677673, 679580077, 337406589, 290818316, 877337160, 901728858, 679284947, 688210097, 692137887, 718203285, 629455728, 941802184};
    vector<int> v4 = {1,3,2};
    string str = "eceeeefasdghjklqwertyuio";
    vector<vector<string>> st  = {{"A","B"},{"C"},{"B","C"},{"D"}};
    vector<string> st1 = {"0.700","2.800","4.900"};

    Solution s;
    s.candyCrush(v6);



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