#include <bits/stdc++.h>

using namespace std;
void print2Dvector(vector<vector<int>>& a)
{
    int m = a.size(), n = a[0].size();
    for(int i = 0; i < m; ++i)
    {
        for(int j = 0; j < n; ++j)
            cout << a[i][j] << " ";
        cout << endl;
    }
}

struct cmp{
    bool operator()(char a, char b) const
    {
        return a > b;
    }
};
class Solution {
public:
    int mergeStones(vector<int>& stones, int K) {
        int n = stones.size();
        if((n-1)%(K-1) != 0) return -1;
        vector<vector<int>> dp(n+1, vector<int>(n+1, INT_MAX));
        vector<int> sum(n+1, 0);
        for(int i = 1; i <= n; i++)
        {
            sum[i] = stones[i-1] + sum[i-1];//前缀和
            dp[i][i] = 0;
        }
        for(int i = 1; i+K-1 <= n; ++i)
            dp[i][i+K-1] = sum[i+K-1]-sum[i-1];
        int c = (n-1)/(K-1);//合并的次数
        for(int t = 2; t <= c; t++)
        {	//第几次合并
            for(int i = 1; i+t*(K-1) <= n; i++)
            {	//要获得区间[i, i+t*K-1]的最优值
                int r = i+t*(K-1);
                for(int j = 0; j < K; j++)//在上一次的结果里，遍历 K+1 种情况
                {
                    dp[i][r] = min(dp[i][r], dp[i+j][r-(K-1-j)]-sum[i-1]+sum[r]);
                }
            }
        }
        print2Dvector(dp);
        return dp[1][n];
    }
};
int main()
{

    Solution s;
    vector<int> a = {3,2,4,1};
    string s1 = "D450";
    cout << s.mergeStones(a,2) << endl;
    return 0;
}