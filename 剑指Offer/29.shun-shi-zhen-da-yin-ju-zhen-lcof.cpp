class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if(matrix.size()==0 || matrix[0].size()==0)
        	return {};
        int i = 0, k = 0, count = matrix.size()*matrix[0].size();
        int left = 0, right = matrix[0].size()-1, up = 0, bottom = matrix.size()-1;
        vector<int> ans(count);
        while(count)
        {
        	i = left;
        	while(count && i <= right)
        	{
        		ans[k++] = matrix[up][i++];
        		count--;
        	}
        	up++,
        	i = up;
        	while(count && i <= bottom)
        	{
        		ans[k++] = matrix[i++][right];
        		count--;
        	}
        	right--;
        	i = right;
        	while(count && i >= left)
        	{
        		ans[k++] = matrix[bottom][i--];
        		count--;
        	}
        	bottom--;
        	i = bottom;
        	while(count && i >= up)
        	{
        		ans[k++] = matrix[i--][left];
        		count--;
        	}
            left++;
        }
        return ans;
    }
};