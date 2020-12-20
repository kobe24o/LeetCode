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
    /**
     * @param n: the number of tasks
     * @param weights: the weight for every task
     * @param tasks: the actual duration of every task
     * @param p: maximum runtime for Pigeon in an hour
     * @return: the maximum total weight that the Pigeon service can achieve in an hour
     */
    int maxWeight(int n, vector<int> &weights, vector<int> &tasks, int p) {
        // write your code here
        vector<vector<int>> dp(n, vector<int>(p+1, -1));
        dp[0][0] = 0;
        if(tasks[0]*2 <= p)
            dp[0][tasks[0]*2] = weights[0];
        for(int i = 1; i < n; i++)
        {
            for(int t1 = 0; t1 < p; t1++)
            {
                if(dp[i-1][t1] != -1 && t1+2*tasks[i] <= p)
                {
                    dp[i][t1+2*tasks[i]] = max(dp[i][t1+2*tasks[i]], dp[i-1][t1]+weights[i]);
                }
            }
        }
        return *max_element(dp[n-1].begin(), dp[n-1].end());
    }
};
int main()
{

    Solution s;
    vector<int> a = {2,4,4,5}, b = {2,2,3, 4};
    string s1 = "D450";
    cout << s.maxWeight(4,a,b,15) << endl;


    return 0;
}