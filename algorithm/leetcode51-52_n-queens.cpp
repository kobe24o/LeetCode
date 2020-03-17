class Solution {
    vector<vector<string>> ans;
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<string> map(n,string(n,'.'));
        for(int i = 0; i < n; ++i)
        {
            map[0][i]='Q';
            dfs(map,0,i,n);
            map[0][i]='.';
        }
        return ans;
    }

    bool isok(vector<string>& map, int x, int y, int &n)
    {
        int i = 1, j = y;
        while(x >= 1)//向上遍历，看冲突不
        {
            if(map[x-1][j]=='Q')//竖直方向
                return false;
            if(j-i>=0 && map[x-1][j-i]=='Q')//左45度
                return false;
            if(j+i<n && map[x-1][j+i]=='Q')//右45度
                return false;
            i++;//45度张角
            x--;//往上找
        }
        return true;
    }

    void dfs(vector<string>& map, int x, int y, int& n)
    {
        if(x==n-1)
            ans.push_back(map);
        for(int i = 0; i < n; ++i)
        {   //x+1下一行
            if(x+1 < n && isok(map,x+1,i,n))
            {
                map[x+1][i] = 'Q';
                dfs(map, x+1, i, n);
                map[x+1][i] = '.';
            }
        }
    }
};