class Solution {
public:
    int maxSizeSlices(vector<int>& slices) {
        int i, j, n = slices.size()/3, k = slices.size();
        int prev_max = 0;
        vector<vector<int>> dp1(n,vector<int>(k,0));
        vector<vector<int>> dp2(n,vector<int>(k,0));
        dp1[0] = slices;
        dp2[0] = slices;
        for(i = 1; i < n; ++i)
        {
        	prev_max = 0;
        	for(j = 0; j < k-1; ++j)
        	{
        		if(j-2 >= 0)
        			prev_max = max(prev_max, dp1[i-1][j-2]);
        		dp1[i][j] = prev_max + slices[j];
        	}

        	prev_max = 0;
        	for(j = 1; j < k; ++j)
        	{
        		if(j-2 >= 1)
        			prev_max = max(prev_max, dp2[i-1][j-2]);
        		dp2[i][j] = prev_max + slices[j];
        	}
        }
        return max(*max_element(dp1[n-1].begin(),dp1[n-1].end()), *max_element(dp2[n-1].begin(),dp2[n-1].end()));
    }
};