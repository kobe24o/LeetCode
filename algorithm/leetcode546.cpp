class Solution {
public:
    int removeBoxes(vector<int>& boxes) {
    	int dp[101][101][101];
    	memset(dp, 0, sizeof dp);
    	//dp[i][j][k] 表示区间[i,j]后面有 k 个连续元素跟 j 相同 
    	int n = boxes.size(), i, j, k, p, len;
    	for(len = 1; len <= n; len++) 
    	{
    		for(i = 0; i+len-1 < n; ++i)
    		{
    			j = i+len-1;
    			for(k = 0; k < n; ++k)
    			{
    				//策略1
    				//消除右侧的k+1个一样的
    				dp[i][j][k] = max(dp[i][j][k], (j-1 < i ? 0 : dp[i][j-1][0])+(k+1)*(k+1));
    				for(p = i; p <= j-1; p++)
    				{
    					//策略2, 消除[p+1,j-1]区间，b[p]==b[j]时
    					if(boxes[p] == boxes[j])
    					{
    						dp[i][j][k] = max(dp[i][j][k], (p+1 > j-1 ? 0 : dp[p+1][j-1][0]) + dp[i][p][k+1]);
    					}
    			}
    		}
    	}
    	return dp[0][n-1][0];
    }
};

class Solution {
public:
    int dp[100][100][100];

    int removeBoxes(vector<int>& boxes) {
        memset(dp, 0, sizeof dp);
        return calculatePoints(boxes, 0, boxes.size() - 1, 0);
    }

    int calculatePoints(vector<int>& boxes, int l, int r, int k) {
        if (l > r) return 0;
        if (dp[l][r][k] != 0) return dp[l][r][k];
        while (r > l && boxes[r] == boxes[r - 1]) {
            r--;
            k++;
        }
        dp[l][r][k] = calculatePoints(boxes, l, r - 1, 0) + (k + 1) * (k + 1);
        for (int i = l; i < r; i++) {
            if (boxes[i] == boxes[r]) {
                dp[l][r][k] = max(dp[l][r][k], calculatePoints(boxes, l, i, k + 1) + calculatePoints(boxes, i + 1, r - 1, 0));
            }
        }
        return dp[l][r][k];
    }
};