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

using namespace std;
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if(amount <= 0)
            return 0;
        int n = coins.size();
//        sort(coins.begin(),coins.end());
        int i, j, m, k = amount/coins[0];
        vector<int> dp(amount+1, INT_MAX);
        dp[0] = 0;

        for(j = 0; j <= amount; ++j)
        {
            if(dp[j] != INT_MAX)
            {
                for(m = 0; m < n; ++m)
                {
                    if(j <= amount-coins[m])
                        dp[j+coins[m]] = min(dp[j]+1, dp[j+coins[m]]);
                    if(dp[amount] != INT_MAX)
                        return dp[amount];
                }
            }
        }
        return -1;
    }
};



int main() {
    Solution s;

    vector<int> v = {456,117,5,145};
    vector<int> v1 = {5,6};
    string str = "eceeeefasdghjklqwertyuio";
    vector<vector<int>> v2 = {{2,1},{3,2}};//{4,2},{5,2},{6,5},{7,1},{8,3},{9,1},{10,1}};
    s.coinChange(v,1459);
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