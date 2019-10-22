class Solution {
public:
    void rotate(vector<vector<int>>& m) {
        int r = m.size(), c = m[0].size(), i, j, k;
        for(i = 0; i < m.size(); ++i)
        {
        	for(j = 0; j < i; ++j)
        		swap(m[i][j], m[j][i]);
        }
        for(i = 0; i < m.size(); ++i)
        {
        	j = 0, k = m[0].size()-1;
        	while(j < k)
        	{
        		swap(m[i][j], m[i][k]);
        		j++,k--;
        	}
        }
    }
};