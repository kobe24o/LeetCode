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
    int nthUglyNumber(int n) {
        int dp[n+1] = {0};
        dp[1] = 1;
        int i2=1, i3=1, i5=1;
        for(int i = 2; i <= n; i++)
        {
            dp[i] = min(dp[i2]*2, min(dp[i3]*3, dp[i5]*5));
            if(dp[i2]*2 == dp[i])
                i2++;
            if(dp[i3]*3 == dp[i])
                i3++;
            if(dp[i5]*5 == dp[i])
                i5++;
        }
        return dp[n];
    }
};




int main() {
    Solution s;

    vector<int> v = {456,117,5,145};
    vector<int> v1 = {5,6};
    string str = "eceeeefasdghjklqwertyuio";
    vector<vector<int>> v2 = {{2,1},{3,2}};//{4,2},{5,2},{6,5},{7,1},{8,3},{9,1},{10,1}};
    s.nthUglyNumber(20);
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