class Solution {
public:
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        sort(arr2.begin(), arr2.end());
        arr2.erase(unique(arr2.begin(), arr2.end()), arr2.end());
        // arr2 排序去重
        int n1 = arr1.size(), n2 = arr2.size();
        vector<vector<int>> dp(n1+1, vector<int>(min(n1,n2)+1, INT_MAX));
        // dp[i][j] 表示前 i 个元素，替换 j 次，最后一个元素的最小值
        dp[0][0] = -1;
        for(int i = 1; i <= n1; ++i) 
        {   
            for(int j = 0; j <= min(n2,i); ++j)
            {
                if(arr1[i-1] > dp[i-1][j])//第 i 个数比 之前的最后一个元素大，不用替换
                    dp[i][j] = min(dp[i][j], arr1[i-1]);
                if(j > 0)
                {
                    auto it = upper_bound(arr2.begin(), arr2.end(), dp[i-1][j-1]);
                    // 前 i-1 个数，替换了 j-1 次的最小尾部值 v，找到arr2中比 v 大的最小值
                    if(it != arr2.end())
                    {
                        dp[i][j] = min(dp[i][j], *it);
                    }
                }
                if(i == n1 && dp[n1][j] != INT_MAX)
                    return j; // 遍历完了arr1
            }
        }
        return -1;
    }
};