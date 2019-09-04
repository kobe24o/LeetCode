class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        if(numRows == 0)
        	return {};
        vector<vector<int>> ans;
        vector<int> row;
        ans.push_back({1});
        int i, j, sum;
        for(i = 1; i < numRows; ++i)
        {
        	row.clear();
        	row.push_back({1});
        	for(j = 1; j < ans[i-1].size()-1; ++j)
        	{
        		sum = ans[i-1][j-1] + ans[i-1][j];
        		row.push_back(sum);
        	}
        	row.push_back({1});
        	ans.push_back(row);
        }
        return ans;
    }
};