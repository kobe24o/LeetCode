class Solution {
    int r,c;
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        if(matrix.size() == 0)
            return {};
        int i = 0, j = 0;
        r = matrix.size(), c = matrix[0].size();
        vector<int> ans;
        for(int k = 0; k <= r+c-1; ++k)
        {
            if(k%2 == 0)
            {
                for(i = r-1; i >= 0; --i)
                {
                    j = k-i;
                    if(j>=0 && j<c)
                        ans.push_back(matrix[i][j]);
                }
            }
            else
            {
                for(i = 0; i < r; ++i)
                {
                    j = k-i;
                    if(j>=0 && j<c)
                        ans.push_back(matrix[i][j]);
                }
            }
        }
        return ans;
    }
};