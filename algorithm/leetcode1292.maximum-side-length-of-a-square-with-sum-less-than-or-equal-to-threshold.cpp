class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
    	int m = mat.size(), n = mat[0].size(), i, j, maxlen = 0, len = 0;
    	vector<vector<int>> sum(m,vector<int>(n,0));
    	for(j = 0; j < n; ++j)
    		sum[0][j] = (j > 0 ? sum[0][j-1] : 0) + mat[0][j];
    	for(i = 1; i < m; ++i)
    		sum[i][0] = sum[i-1][0] + mat[i][0];
    	for(i = 1; i < m; ++i)
    		for(j = 1; j < n; ++j)
    			sum[i][j] = sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1]+mat[i][j];
    	int ni, nj, sumofarea;
		for(i = 0; i < m; ++i)
			for(j = 0; j < n; ++j)
				for(len = maxlen+1; len <= min(m,n); ++len)
				{
					ni = i+len-1;
					nj = j+len-1;
					if(ni < m && nj < n && sum[ni][nj]-(i>0?sum[i-1][nj]:0)-(j>0?sum[ni][j-1]:0)
										+(i>0&&j>0 ? sum[i-1][j-1] : 0) <= threshold)
					{
                        maxlen = max(maxlen, len);
                        if(maxlen == min(m,n))
                            return maxlen;
					}
                    else
                        break;
				}
		return maxlen;
    }
};