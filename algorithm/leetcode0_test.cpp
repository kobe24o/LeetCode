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

class Solution {
	int sum = 0;
	int r,c;
	vector<vector<int>> dir = {{1,0},{-1,0},{0,1},{0,-1}};
public:
    /**
     * @param m: the row
     * @param n: the column
     * @return: the possible unique paths
     */
    int uniquePaths(int m, int n) {
        if(m==0 || n==0)
        	return 0;
        r= m, c= n;
        vector<vector<int>> map(m,vector<int>(n,1));
        map[0][0] = 0;
        dfs(map,0,0);
        return sum;
    }

    void dfs(vector<vector<int>>& map, int i, int j)
    {
    	if(i==r-1 && j==c-1)
    	{
    		sum++;
    		return;
    	}
    	int x, y;
    	for(int k = 0; k < 4; ++k)
    	{
    		x = i+dir[k][0];
    		y = j+dir[k][1];
    		if(x>=0&&x<r&&y>=0&&y<c&&map[x][y])
    		{
    			map[x][y]=0;
    			dfs(map,x,y);
    			map[x][y]=1;
    		}
    	}
    }
};

int main() {
    vector<vector<int>> v = {{1,3,2},{4,6,5},{7,9,8},{13,15,14},{10,12,11}};
    vector<int> v1 = {7,5,6,4};
    vector<int> v3 = {21,44,5,21,33,38,23,5,25,43};
    string str = "eceeeefasdghjklqwertyuio";
    vector<vector<int>> v2 = {{3,7,8},{9,11,13},{15,16,17}};

    Solution s;
    s.uniquePaths(3,3);


    TreeNode *t1 = new TreeNode(1);
    TreeNode *t2 = new TreeNode(2);
    TreeNode *t3 = new TreeNode(3);
    TreeNode *t4 = new TreeNode(4);
    TreeNode *t5 = new TreeNode(5);
    t1->left = t2;
    t2->right = t3;
    t3->left = t4;
    t3->right = t5;


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