class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int i = 0, j = n-1, count = 0, i0;
        while(i < m && grid[i][n-1] >= 0)
        	i++;//这个while可以删除，程序一样正确
        while(i < m && j >= -1)
        {
        	while(j >= 0 && grid[i][j] < 0)
        		j--;
        	count += n-1-j;
        	i++;
        }
        return count;
    }
};