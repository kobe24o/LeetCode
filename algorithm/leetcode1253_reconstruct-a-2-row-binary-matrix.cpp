class Solution {
public:
    vector<vector<int>> reconstructMatrix(int upper, int lower, vector<int>& colsum) {
        int i, n = colsum.size(), sum = 0;
        for(i = 0; i < n; ++i)
        	sum += colsum[i];
        if(upper+lower != sum || upper > n || lower > n)
        	return {};
        vector<vector<int>> ans(2, vector<int> (n,0));
        for(i = 0; i < n; ++i)
        {
        	if(colsum[i] == 0)
        		continue;
        	if(colsum[i] == 2)
        	{
        		ans[0][i] = ans[1][i] = 1;
        		upper--,lower--;
        	}
        	else// colsum[i] == 1，平均着分配
        	{
        		if(lower >= upper)
        		{
        			ans[1][i] = 1;
        			lower--;
        		}
        		else
        		{
        			ans[0][i] = 1;
        			upper--;
        		}
        	}

        	if(lower < 0 || upper < 0)
    			return {};
        }
        return ans;
    }
};