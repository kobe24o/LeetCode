class Solution {
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
    	vector<int> degree(n,0);
    	for(auto& c : connections)
    	{
    		degree[c[0]]++;
    		degree[c[1]]++;
    	}
    	for(int i = 0; i < n; ++i)
    	{
    		
    	}
    }
};