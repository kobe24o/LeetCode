class Solution {
    vector<vector<int>> ans;
public:
    void solveSudoku(vector<vector<int>> &b) {
        dfs(b,0);
        b = ans;
    }
    
    void dfs(vector<vector<int>> &b, int idx)
    {
        if(idx > 80)
        {
            ans = b;
            return;
        }
        int i = idx/9, j = idx%9;//idx是序号，转换成行列标号
        if(b[i][j] != 0)
            dfs(b,idx+1);//数字是已给的，跳过
        else
        {
            for(int k = 1; k <= 9; ++k)
            {	//遍历9个数字
                if(isok(b,i,j,k))
                {	//数字 k 在当前格子合法
                    b[i][j] = k;
                    dfs(b,idx+1);
                    b[i][j] = 0;
                }
            }
        }
    }
    
    bool isok(vector<vector<int>> &b, int i, int j, int& num)
    {	
        int box_i, box_j;
        box_i = i/3, box_j = j/3;//行列坐标算出小9宫格的坐标
        for(int k = 0; k < 9; ++k)
        {	//遍历9个格子，行的，列的，9 宫格内的，都不能出现过 num
            if(b[i][k]==num || b[k][j]==num || b[box_i*3+k/3][box_j*3+k%3]==num)
                return false;
        }
        return true;
    }
};