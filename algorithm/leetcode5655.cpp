class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> h(matrix);
        int area = 0;
        for(int i = 0; i < m; i++)
        {
            vector<int> height;
            for(int j = 0; j < n; j++)
            {
                if(matrix[i][j] == 0)
                    h[i][j] = 0;
                else
                    h[i][j] += i > 0 ? h[i-1][j] : 0;
                if(h[i][j] > 0)
                    height.push_back(h[i][j]);
            }
            sort(height.begin(), height.end());
            int width = height.size();
            for(int k = 0; k < width; k++)
            {
                area = max(area, height[k]*(width-k));
            }
        }
        return area;
    }
};