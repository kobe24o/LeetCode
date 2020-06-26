class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
    	unordered_map<string,int> m;
    	string s(matrix[0].size(),' ');
    	for(auto& mat : matrix)
    	{
    		if(mat[0] == 0)
    		{
    			for(int i = 0; i < mat.size(); ++i)
    			{
    				mat[i] ^= 1;
    				s[i] = mat[i] ? '1' : '0';
    			}
    		}
    		else
    		{
    			for(int i = 0; i < mat.size(); ++i)
    				s[i] = mat[i] ? '1' : '0';
    		}
    		m[s]++;
    	}
    	int maxCount = 0;
    	for(auto it = m.begin(); it != m.end(); ++it)
    		maxCount = max(maxCount, it->second);
    	return maxCount;
    }
};