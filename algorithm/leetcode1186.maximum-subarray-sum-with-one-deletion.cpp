class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int i, n = arr.size(), maxSum = INT_MIN;
        vector<vector<int>> dp(n, vector<int>(2,INT_MIN));
        dp[0][0] = arr[0];//0位置，不删除元素，最大子序和
        dp[0][1] = 0; //0位置，删除元素，最大子序和
        maxSum = arr[0];
        for(i = 1; i < n; ++i)
        {
        	// i-1 位置处之前没有删除过，i位置处也不删， 或者 只有 i 自己
            dp[i][0] = max(arr[i], dp[i-1][0]+arr[i]);
            maxSum = max(maxSum, dp[i][0]);
            // i-1 位置之前删除过，i位置处不删   或者   i-1之前没有删，删除 i 位置
            dp[i][1] = max(dp[i-1][1]+arr[i], dp[i-1][0]);
            maxSum = max(maxSum, dp[i][1]);
        }
        return maxSum;
    }
};