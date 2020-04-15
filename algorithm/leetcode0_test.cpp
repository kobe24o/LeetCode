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
    vector<int> findSquare(vector<vector<int>>& mat) {
        if(mat.size()==0 || mat[0].size() == 0)
            return {};
        int m = mat.size(), n = mat[0].size(), i, j, k;
        vector<vector<int>> sumof0Up(m, vector<int>(n,0));//向上连续0个数
        vector<vector<int>> sumof0Left(m, vector<int>(n,0));//向左连续0个数
        for(i = 0; i < m; i++)
        {
            for(j = 0; j < n; j++)
            {
                if(mat[i][j] == 0)
                {
                    if(i==0 && j==0)
                        sumof0Left[i][j] = 1, sumof0Up[i][j] = 1;
                    else if(i==0 && j>0)
                    {
                        sumof0Left[i][j] = sumof0Left[i][j-1]+1;
                        sumof0Up[i][j] = 1;
                    }
                    else if(j==0 && i > 0)
                    {
                        sumof0Left[i][j] = 1;
                        sumof0Up[i][j] = sumof0Up[i-1][j]+1;
                    }
                    else
                    {
                        sumof0Left[i][j] = sumof0Left[i][j-1]+1;
                        sumof0Up[i][j] = sumof0Up[i-1][j]+1;
                    }
                }
            }
        }
        vector<int> ans(3,-1);
        int edge, x, y;
        for(i = m-1; i >= 0; i--)
        {
            for(j = n-1; j >= 0; --j)
            {
                edge = min(sumof0Up[i][j], sumof0Left[i][j]);
                while(edge > 0)
                {
                    if(ans[2] > edge)//肯定小，不必检查了
                        break;
                    x = i-edge+1;
                    y = j-edge+1;
                    if(sumof0Up[x][j]>=edge && sumof0Left[i][y]>=edge)
                    {
                        if(edge > ans[2])
                        {
                            ans[2] = edge;
                            ans[0] = x;
                            ans[1] = y;
                        }
                        else if(edge == ans[2] && x <= ans[0])
                        {
                            if(x < ans[0])
                            {
                                ans[0] = x;
                                ans[1] = y;
                            }
                            if(x == ans[0] && y < ans[1])
                                ans[1] = y;
                        }
                    }
                    edge--;
                }
            }
        }
        if(ans[0]==-1)
            return {};
        return ans;
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
    vector<vector<int>> v6 ={{1,0,1},{0,0,1},{0,0,1}};
    vector<int> v1 = {68,130,64};
    vector<int> v2 = {-230,194,7};
    vector<int> v3 = {-1,0};
    vector<int> v4 = {3,2};
    string str = "eceeeefasdghjklqwertyuio";
    vector<vector<int>> v5 = {{2,4,3},{6,5,2}};
    vector<string> st  = {"a","aa"};
    vector<string> st1 = {};
    Solution s;
    v4 = s.findSquare(v6);
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