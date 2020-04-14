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
public:
    vector<int> bestLine(vector<vector<int>>& points) {
    	int i, j, g, dx, dy, maxCount = 0, n = points.size();
    	double k, b;

    	unordered_map<double,unordered_map<double,vector<int>>> m;
    	unordered_map<double,vector<int>> v;
    	vector<int> ansline;
    	for(i = 0; i < n-1; ++i)
    	{
    		for(j = i+1; j < n; ++j)
    		{
    			dx = points[j][0]-points[i][0];
    			dy = points[j][1]-points[i][1];
    			if(dx==0)
    			{
    				if(v[double(points[i][0])].empty())
    					v[double(points[i][0])].push_back(i);
    				v[double(points[i][0])].push_back(j);
    			}
    			else if(dy==0)
    			{
    				if(m[0.0][double(points[i][1])].empty())
    					m[0.0][double(points[i][1])].push_back(i);
    				m[0.0][double(points[i][1])].push_back(j);
    			}
    			else
    			{
    				k = double(dy)/dx;
    				b = points[i][0]-points[i][1]/k;
    				if(m[k][b].empty())
    					m[k][b].push_back(i);
    				m[k][b].push_back(j);
    			}
    		}
    	}
    	int i1=0;
    	for(auto& mi : m)
    	{
    		for(auto& mii : mi.second)
    		{
    		    i1++;
                if(mii.second.size() > maxCount)
                {
                    maxCount = mii.second.size();
                    ansline = mii.second;
                    cout << i1 << endl;
                }
    		}
    	}
    	for(auto& vi : v)
    	{
    	    i1++;
    		if(vi.second.size() > maxCount)
			{
				maxCount = vi.second.size();
				ansline = vi.second;
                cout << i1 << endl;
			}
    	}
    	return {ansline[0],ansline[1]};
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
    vector<vector<int>> v6 = {{-13260,8589},{1350,8721},{-37222,-19547},{-54293,-29302},{-10489,-13241},{-19382,574},{5561,1033},{-22508,-13241},{-1542,20695},{9277,2820},{-32081,16145},{-50902,23701},{-8636,19504},{-17042,-28765},{-27132,-24156},{-48323,-4607},{30279,29922}};
    vector<int> v1 = {68,130,64};
    vector<int> v2 = {-230,194,7};
    vector<int> v3 = {-1,0};
    vector<int> v4 = {3,2};
    string str = "eceeeefasdghjklqwertyuio";
    vector<vector<int>> v5 = {{2,4,3},{6,5,2}};
    vector<string> st  = {"a","aa"};
    vector<string> st1 = {};
    Solution s;
    s.bestLine(v6);
    printv(v1);
    v1.resize(3);
    printv(v1);
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