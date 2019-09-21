class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        int r0 = nums.size(), c0 = nums[0].size();
        if(r*c != r0*c0)
        	return nums;
        vector<int> row;
        vector<vector<int>> matrix;
        int i, j, k = 0;
        for(i = 0; i < r0; ++i)
        {
        	for(j = 0; j < c0; ++j)
        	{
        		row.push_back(nums[i][j]);
        		k++;
        		if(k == c)
        		{
        			matrix.push_back(row);
        			k = 0;
        			row.clear();
        		}
        	}
        }
        return matrix;
    }
};