class Solution {
public:
    int maximalRectangle(vector<vector<char>>& mat) {
        if(matrix.empty())
            return 0;
        int i, j, minL, maxR, maxarea = 0;
        int r = mat.size(), c = mat[0].size();
        vector<vector<int>> left(r,vector<int>(c,0));
        vector<vector<int>> right(r,vector<int>(c,c));
        vector<vector<int>> height(r,vector<int>(c,0));
        for(i = 0; i < r; i++) 
        {
            //填写left，相连的1,先到最高，然后最左侧的下标
            minL = 0;
            for(j = 1; j < c; j++)
            {
                if(i == 0)
                {
                    if(mat[i][j] == 1)
                    {
                        if(mat[i][j-1]==0)
                            minL = j;
                        left[i][j] = minL;
                    }
                }
                else
                {
                    if(mat[i][j] == 1)
                    {
                        if(mat[i][j-1]==0)
                            minL = j;
                        left[i][j] = max(minL,left[i-1][j]);
                    }
                }
            }

            maxR = c;
            for(j = c-2; j >= 0; j--)
            {
                if(i == 0)
                {
                    if(mat[i][j] == 1)
                    {
                        if(mat[i][j+1]==0)
                            maxR = j;
                        right[i][j] = maxR;
                    }
                }
                else
                {
                    if(mat[i][j] == 1)
                    {
                        if(mat[i][j+1]==0)
                            maxR = j;
                        right[i][j] = min(maxR,right[i-1][j]);
                    }
                }
            }

            for(j = 0; j < c; j++)
            {
                if(i == 0)
                {
                    if(mat[i][j] == 1)
                        height[i][j] = 1;
                }
                else
                {
                    if(mat[i][j] == 1)
                        height[i][j] = 1+height[i-1][j];
                }
            }
        }

        for(i = 0; i < r; i++)
            for(j = 0; j < c; j++)
                maxarea = max(maxarea, (right[i][j]-left[i][j])*height[i][j]);
        return maxarea;//返回最大面积
    }
};