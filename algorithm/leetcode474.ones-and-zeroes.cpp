class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
    	int i, j, k = 0, zero, len = strs.size(), maxcount = 0;
    	vector<vector<int>> onezero(len);
    	for(i = 0; i < len; ++i)
    	{
    		zero = 0;
    		for(j = 0; j < strs[i].size(); ++j)
    			if(strs[i][j]=='0')
    				zero++;
    		onezero[k++] = {zero, strs[i].size()-zero};
    	}
    	vector<vector<vector<int>>> dp(len,vector<vector<int>>(len,vector<int>(3,0)));
    	
    }
};