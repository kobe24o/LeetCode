class Solution {
public:
    vector<int> getMaxMatrix(vector<vector<int>>& matrix) {
    	int m = matrix.size(), n = matrix[0].size(), i, j, x, y;
    	int sum, maxSum = INT_MIN;
    	vector<vector<int>> prefixsum(matrix);
    	for(i = 0; i < m; ++i)
    	{
    		for(j = 0; j < n; ++j)
    		{
    			if(i > 0)
    				prefixsum[i][j] += prefixsum[i-1][j];
    			if(j > 0)
    				prefixsum[i][j] += prefixsum[i][j-1];
    			if(i>0 && j>0)
    				prefixsum[i][j] -= prefixsum[i-1][j-1];
                // cout << prefixsum[i][j] << " ";
    		}
            // cout << endl;
    	}
    	vector<int> ans(4);
    	for(i = 0; i < m; i++)
    	{
    		for(j = 0; j < n; ++j)
    		{
    			for(x = 0; x <= i; x++)
    			{
    				for(y = 0; y <= j; y++)
    				{
    					sum = prefixsum[i][j];
    					if(x > 0)
    						sum -= prefixsum[x-1][j];
    					if(y > 0)
    						sum -= prefixsum[i][y-1];
    					if(x > 0 && y > 0)
    						sum += prefixsum[x-1][y-1];
    					if(sum > maxSum)
    					{
    						maxSum = sum;
    						ans[0] = x, ans[1] = y;
    						ans[2] = i, ans[3] = j;
    					}
    				}
    			}
    		}
    	}
    	return ans;
    }
};

class Solution {
public:
    vector<int> getMaxMatrix(vector<vector<int>>& matrix) {
    	int m = matrix.size(), n = matrix[0].size(), i, j, k, l, r;
    	int sum, maxSum = INT_MIN;
    	vector<int> sumRi_Rj(n);//【i，j】行的列向和
    	vector<int> ans(4);
    	for(i = 0; i < m; ++i)
    	{
    		sumRi_Rj.clear();
    		sumRi_Rj.resize(n,0);
    		for(j = i; j < m; ++j)
    		{
    			for(k = 0; k < n; ++k)
    			{
    				sumRi_Rj[k] += matrix[j][k];
    			}
    			sum = sumRi_Rj[0];
    			l = r = 0;
                if(sum > maxSum)
                {
                    maxSum = sum;
                    ans[0] = i, ans[1] = l;
                    ans[2] = j, ans[3] = r;
                }
    			for(k = 1; k < n; ++k)
    			{   //转为一维数组sumRi_Rj最大子数组和
    				if(sum > 0)
    				{
    					sum += sumRi_Rj[k];
    					r = k;
    				}
    				else
    				{
    					sum = sumRi_Rj[k];
    					l = r = k;
    				}
    				if(sum > maxSum)
    				{
    					maxSum = sum;
    					ans[0] = i, ans[1] = l;
    					ans[2] = j, ans[3] = r;
    				}
    			}
    		}
    	}
    	return ans;
    }
};