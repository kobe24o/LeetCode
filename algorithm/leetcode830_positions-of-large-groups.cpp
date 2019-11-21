class Solution {
public:
    vector<vector<int>> largeGroupPositions(string S) {
        int i = 0, j = 0, len = 1;
        vector<vector<int>> ans;
        char prev = '*';
        for( ; j < S.size(); ++j)
        {
        	if(S[j] == prev)
        	{
        		len++;
        		if(j == S.size()-1 && len >= 3)
        			ans.push_back({i,j});
        	}
        	else
        	{
        		if(len >= 3)
        			ans.push_back({i,j-1});
        		prev = S[j];
        		len = 1;
        		i = j;
        	}
        }
        return ans;
    }
};