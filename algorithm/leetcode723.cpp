class Solution {
public:
    vector<vector<int>> candyCrush(vector<vector<int>>& b) {
        bool todo = false;
        int m = b.size(), n = b[0].size(), i, j, up, down;
        for(i = 0; i < m; ++i)//横向检查
            for(j = 0; j < n-2; ++j)
            {
                if(b[i][j] == 0)
                    continue;
                if(abs(b[i][j])==abs(b[i][j+1]) && abs(b[i][j+1])==abs(b[i][j+2]))
                {
                    b[i][j] = b[i][j+1] = b[i][j+2] = -abs(b[i][j]);//标记为负的
                    todo = true;
                }
            }
        for(j = 0; j < n; ++j)//纵向检查
            for(i = 0; i < m-2; ++i)
            {
                if(b[i][j] == 0)
                    continue;
                if(abs(b[i][j])==abs(b[i+1][j]) && abs(b[i+1][j])==abs(b[i+2][j]))
                {
                    b[i][j] = b[i+1][j] = b[i+2][j] = -abs(b[i][j]);//标记为负的
                    todo = true;
                }
            }
        for(i = 0; i < m; ++i)//负的 标记为0要删除
            for(j = 0; j < n; ++j)
                if(b[i][j] < 0)
                    b[i][j] = 0;
        for(j = 0; j < n; ++j)//纵向掉落
        {
            down = up = m-1;//从最底下开始往上找
            while(down >= 0)
            {   //双指针搬移数据
                if(b[down][j] == 0)//底下待填
                {
                    up = min(down, up);//up记住上次的位置
                    while(up >= 0 && b[up][j] == 0)
                        up--;
                    if(up >= 0)//上面找到糖果
                        swap(b[down][j], b[up][j]);//交换
                    else
                        break;//找完了
                }
                down--;
            }
        }
        if(todo)
            candyCrush(b);
        return b;
    }
};