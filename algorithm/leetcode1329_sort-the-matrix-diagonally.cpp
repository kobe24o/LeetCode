class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        int i = 0, x, y, k;
        vector<int> v;
        for( ; i < n; ++i)
        {
            v.clear();//临时存储
            x = 0,y=i;//先把第一行开头的遍历掉
            while(x < m && y < n)//在范围内
            {
                v.push_back(mat[x][y]);
                x++,y++;//对角线移动
            }
            sort(v.begin(),v.end());//排序
            x = 0, y = i, k =0;
            while(x < m && y < n)
            {
                mat[x][y] = v[k];//写回数组
                x++,y++,k++;
            }
        }
        for(i=1 ; i < m; ++i)
        {
            v.clear();
            x = i,y=0;//第一列剩余的开头的遍历掉
            while(x < m && y < n)
            {
                v.push_back(mat[x][y]);
                x++,y++;
            }
            sort(v.begin(),v.end());
            x = i, y = 0, k =0;
            while(x < m && y < n)
            {
                mat[x][y] = v[k];
                x++,y++,k++;
            }
        }
        return mat;
    }
};