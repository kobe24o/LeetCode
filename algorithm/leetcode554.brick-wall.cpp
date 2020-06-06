class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
    	int pos = 0, n = wall.size(), minbrick = INT_MAX;
    	unordered_map<int,int> m;//pos，计数
    	for(int i = 0, j; i < n; i++) 
    	{
    		pos = 0;
    		for(j = 0; j < wall[i].size()-1; j++)
    		{
    			pos += wall[i][j];
    			m[pos]++;
    		}
    	}
    	for(auto it = m.begin(); it != m.end(); ++it)
    		minbrick = min(minbrick, n-it->second);
    	return minbrick==INT_MAX ? n : minbrick;
    }
};