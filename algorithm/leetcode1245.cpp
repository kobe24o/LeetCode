class Solution {
public:
    int treeDiameter(vector<vector<int>>& edges) {
    	int n = edges.size()+1;
    	vector<vector<int>> map(n,vector<int>(n,0))
    	for(auto& e : edges)
    	{
    		m[e[0]][e[1]] = 1;
    		m[e[1]][e[0]] = 1;
    	}

    }
};