class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        if(matrix.size()==0 || matrix[0].size() == 0)
        	return false;
        int m = matrix.size(), n = matrix[0].size(), i, j;
        i = 0, j = n-1;
        while(i<m && j>=0)
        {
        	if(matrix[i][j] < target)
        		i++;
        	else if(matrix[i][j] > target)
        		j--;
        	else
        		return true;
        }
        return false;
    }
};