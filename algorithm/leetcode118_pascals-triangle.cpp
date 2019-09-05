class Solution {
public:
    vector<vector<int>> generate(int numRows) {
    	vector<vector<int>> ans;
        vector<int> row;
        if(numRows == 0)
        	return ans;
        else if(numRows == 1)
    	{
    		row.push_back(1);
    		ans.push_back(row);
    		return ans;
    	}
        else if(numRows == 2)
    	{
    		row.push_back(1);
    		ans.push_back(row);
    		return ans;
    	}
        int i, j, sum;
        for(i = 2; i < numRows; ++i)
        {
        	row.clear();
        	row.push_back(1);
        	for(j = 1; j < ans[i-1].size(); ++j)
        	{
        		sum = ans[i-1][j-1] + ans[i-1][j];
        		row.push_back(sum);
        	}
        	row.push_back(1);
        	ans.push_back(row);
        }
        return ans;
    }
};