class Solution {
public:
    vector<vector<int>> multiSearch(string big, vector<string>& smalls) {
    	unordered_map<char,vector<int>> m;
    	int i, j, n = smalls.size();
    	bool found;
    	vector<vector<int>> ans(n);
    	for(i = 0; i < big.size(); ++i)
    		m[big[i]].push_back(i);
    	for(i = 0; i < n; ++i)
    	{
    		if(smalls[i].empty())
    			continue;
    		for(auto idx : m[smalls[i][0]])
    		{
    			found = true;
    			if(big.size()-idx < smalls[i].size())
    				break;
    			for(j = 0; j < smalls[i].size(); ++j)
    			{
    				if(big[idx+j] != smalls[i][j])
    				{
    					found = false;
    					break;
    				}
    			}
    			if(found)
    				ans[i].push_back(idx);
    		}
    	}
    	return ans;
    }
};

class Solution {
public:
    vector<vector<int>> multiSearch(string big, vector<string>& smalls) {
    	
    }
};