class Solution {
public:
    int longestLine(vector<vector<int>>& M) {
    	if(M.empty() || M[0].empty())
    		return 0;
        int m = M.size(), n = M[0].size(), i, j;
        vector<vector<int>> h(m,vector<int>(n,0)),
        	v(m,vector<int>(n,0)), p_45(m,vector<int>(n,0)),
        	n_45(m,vector<int>(n,0));
    	int maxlen = 0;
    	for(i = 0; i < m; i++) 
    	{
    		for(j = 0; j < n; j++)
    		{
    			if(M[i][j] == 0)
    				continue;
    			h[i][j] = i-1>=0 ? h[i-1][j]+1 : 1;
    			v[i][j] = j-1>=0 ? v[i][j-1]+1 : 1;
    			p_45[i][j] = (i>0 && j+1 <n) ? p_45[i-1][j+1]+1 : 1;
    			n_45[i][j] = (i>0 && j>0) ? n_45[i-1][j-1]+1 : 1;
    			maxlen = max(maxlen,h[i][j]);
    			maxlen = max(maxlen,v[i][j]);
    			maxlen = max(maxlen,p_45[i][j]);
    			maxlen = max(maxlen,n_45[i][j]);
    		}
    	}
    	return maxlen;
    }
};