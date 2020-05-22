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
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        int n = price.size();
        int i,j,a,b,c,d,e,f, money;
        for(i = 0; i < n; ++i)
        {
            vector<int> bag(7,0);
            bag[i] = 1;
            bag[6] = price[i];
            special.push_back(bag);
        }
        int dp[7][7][7][7][7][7];
        dp[0][0][0][0][0][0] = 0;
        vector<int> t(6,0);
        while(needs.size() < 6)
            needs.push_back(0);
        for(i = 0; i < needs.size(); ++i)
            t[i] = needs[i];
        memset(dp,0x7f,sizeof(dp));
        for(vector<int> & s : special)
        {
            vector<int> nd(6,0);
            money = s.back();
            for(j = 0; j < s.size()-1; ++j)
                nd[j] = s[j];
            for(a = 0; a <= t[0]; ++a)
                for(b = 0; b <= t[1]; ++b)
                    for(c = 0; c <= t[2]; ++c)
                        for(d = 0; d <= t[3]; ++d)
                            for(e = 0; e <= t[4]; ++e)
                                for(f = 0; f <= t[5]; ++f)
                                {
                                    if(dp[a][b][c][d][e][f] != 0x7fffffff && a+nd[0] <= needs[0]
                                       && b+nd[1] <= needs[1] && c+nd[2] <= needs[2]
                                       && d+nd[3] <= needs[3] && e+nd[4] <= needs[4]
                                       && f+nd[5] <= needs[5])
                                        // cout << dp[a][b][c][d][e][f] << " ";
                                        dp[a+nd[0]][b+nd[1]][c+nd[2]][d+nd[3]][e+nd[4]][f+nd[5]]
                                                = min(dp[a+nd[0]][b+nd[1]][c+nd[2]][d+nd[3]][e+nd[4]][f+nd[5]],
                                                      dp[a][b][c][d][e][f]+money);
                                }
        }
        return dp[t[0]][t[1]][t[2]][t[3]][t[4]][t[5]];
    }
};
void printv(vector<int>& v)
{
    for(auto& vi : v)
        cout << vi << " ";
    cout << endl;
}
int main() {
//    vector<vector<int>> v6 = {{-13260,8589},{1350,8721},{-37222,-19547},{-54293,-29302},{-10489,-13241},{-19382,574},{5561,1033},{-22508,-13241},{-1542,20695},{9277,2820},{-32081,16145},{-50902,23701},{-8636,19504},{-17042,-28765},{-27132,-24156},{-48323,-4607},{30279,29922}};
    vector<vector<int>> v6 ={{5,3},{3,0},{5,1},{1,1},{1,5},{3,0},{0,2}};
    vector<vector<int>> v5 ={{1,1,0,4},{2,2,1,9}};
    vector<int> v1 = {197,130,1};
    vector<int> v2 = {2,3,4};
    vector<int> v3 = {-1,-2,-3,-4,-5};
    vector<int> v4 = {{1,2,1}};
    string str = "eceeeefasdghjklqwertyuio";
    vector<vector<string>> st  = {{"A","B"},{"C"},{"B","C"},{"D"}};

    vector<string> st1 = {};
    Solution s;
    s.shoppingOffers(v2,v5,v4);
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