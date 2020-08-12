class Solution {
public:
    vector<int> cheapestJump(vector<int>& A, int B) {
        int n = A.size(), i, len, cost, idx = n-1;
        vector<int> dp(n, INT_MAX);
        vector<vector<int>> path(n);
        dp[0] = A[0];
        path[0] = {1};
        for(i = 0; i < n-1; i++) 
        {
        	if(dp[i] == INT_MAX)
        		continue;
        	for(len = 1; len <= B; len++)
        	{
        		if(i+len < n && A[i+len] != -1)
        		{
        			if(dp[i+len] > dp[i]+A[i+len])
        			{
        				dp[i+len] = dp[i]+A[i+len];
        				path[i+len] = path[i];
        				path[i+len].push_back(i+len+1);
        			}
        			else if(dp[i+len] == dp[i]+A[i+len])
        			{
        				auto temp = path[i];
        				temp.push_back(i+len+1);
        				if(temp < path[i+len])
        					path[i+len] = temp;
        			}
        		}
        	}
        }
        return path[n-1];
    }
};