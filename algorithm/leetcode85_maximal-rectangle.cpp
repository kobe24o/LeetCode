class Solution {
public:
    int maximalRectangle(vector<vector<char>>& mat) {
        if(mat.empty())
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
                if(i == 0)//第一行
                {
                    if(mat[i][j] == '1')
                    {
                        if(mat[i][j-1] == '0')
                            minL = j;//左边0，当前1，需要更新最左边的边界minL
                        left[i][j] = minL;
                    }
                }
                else//剩余行
                {
                    if(mat[i][j] == '1')
                    {
                        if(mat[i][j-1] == '0')
                            minL = j;
                        left[i][j] = max(minL,left[i-1][j]);//跟上面的行，比较，取大
                    }
                }
            }

            maxR = c;
            for(j = c-2; j >= 0; j--)
            {
                if(i == 0)//第一行
                {
                    if(mat[i][j] == '1')
                    {
                        if(mat[i][j+1] == '0')
                            maxR = j+1;//右边0，当前1，更新最右边的边界maxR
                        right[i][j] = maxR;
                    }
                }
                else//其余
                {
                    if(mat[i][j] == '1')
                    {
                        if(mat[i][j+1] == '0')
                            maxR = j+1;
                        right[i][j] = min(maxR,right[i-1][j]);//还要更上面的比较，取小
                    }
                }
            }

            for(j = 0; j < c; j++)
            {
                if(i == 0)//第一行
                {
                    if(mat[i][j] == '1')
                        height[i][j] = 1;
                }
                else//剩余
                {
                    if(mat[i][j] == '1')
                        height[i][j] = 1+height[i-1][j];
                }
            }

            for(j = 0; j < c; j++)
                maxarea = max(maxarea, (right[i][j]-left[i][j])*height[i][j]);
        }
        return maxarea;//返回最大面积
    }
};