class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size(), i, j;
        int MAX, MIN;
        vector<int> ans;
        set<int> s;
        for(i = 0; i < m; ++i)
        {
        	MIN = INT_MAX;
        	for(j = 0; j < n; ++j)
        	{
        		MIN = min(MIN, matrix[i][j]);
        	}
        	s.insert(MIN);
        }
        for(j = 0; j < n; ++j)
        {
        	MAX = INT_MIN;
        	for(i = 0; i < m; ++i)
        	{
        		MAX = max(MAX, matrix[i][j]);
        	}
        	if(s.count(MAX))
                ans.push_back(MAX);
        }
        return ans;
    }
};