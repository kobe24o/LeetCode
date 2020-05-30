class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& mat, int k) {
    	if(mat.empty() || mat[0].empty())
    		return 0;
    	int m = mat.size(), n = mat[0].size(), i, j1, j2;
    	int sum, tempmax, maxsum = INT_MIN, prefix;
    	vector<int> sumCols(m);
    	for(j1 = 0; j1 < n; ++j1)
    	{
    		sumCols.clear();
    		sumCols.resize(m);
    		for(j2 = j1; j2 < n; ++j2)
    		{
    			for(i = 0; i < m; ++i)
    				sumCols[i] += mat[i][j2];//行向求和
    			sum = tempmax = INT_MIN;   		
	    		for(i = 0; i < m; ++i)
	    		{
	    			if(sum > 0)
	    				sum += sumCols[i];
	    			else
	    				sum = sumCols[i];
	    			tempmax = max(sum, tempmax);
                    if(sum <= k)
	    			    maxsum = max(maxsum, sum);
	    		}
	    		if(tempmax == k || maxsum==k)
	    			return k;
	    		if(tempmax < k)
	    			continue;
	    		set<int> s;
                s.insert(0);//第一个就是k的时候，可以找到
                prefix = 0;
    			for(i = 0; i < m; ++i)
    			{
                    prefix += sumCols[i];
                    auto it = s.lower_bound(prefix-k);
                    s.insert(prefix);
                    if(it != s.end())
                    {
                    	int SUM = prefix-(*it);
                    	if(SUM > maxsum)
                    		maxsum = SUM;
                    }
                    if(maxsum == k)
                    	return k;
                }
    		}
    	}
    	return maxsum;
    }
};