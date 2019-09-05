class Solution {
public:
    vector<vector<int>> generate(int numRows) {
    	vector<vector<int>> ans(numRows);
    	//要使用下标操作，提前写（numRows）
        if(numRows == 0)
        	return ans;
        int i, j;
        for(i = 0; i < numRows; ++i)
        {
        	for(j = 0; j <= i; ++j)
        	{
        		if(j == 0 || j == i)
        			ans[i].push_back(1);
        		else
        			ans[i].push_back(ans[i-1][j-1] + ans[i-1][j]);
        	}
        }
        return ans;
    }
};