class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size(), k = 1;
        vector<int> pos(n*n+1, 0);
        vector<bool> vis(n*n+1, false);
        bool flag = true;
        for(int i = n-1; i >= 0; i--) 
        {
            if(flag)
            {
                for(int j = 0; j < n; j++)
                    pos[k++] = board[i][j];
            }
            else
            {
                for(int j = n-1; j >= 0; j--)
                    pos[k++] = board[i][j];
            }
            flag = !flag;
        }//地图展平
        vis[1] = true;
        queue<int> q;
        q.push(1);//id
        int id, n_id, size, step = 0;
        while(!q.empty())
        {
            size = q.size();
            while(size--)
            {
                id = q.front();
                if(id == n*n)
                    return step;
                q.pop();
                for(k = 1; k <= 6; k++)
                {
                    n_id = id+k;
                    if(n_id > n*n)
                        break;
                    if(pos[n_id] != -1 && !vis[pos[n_id]])
                    {   //是个梯子，可以到达pos[n_id]
                        vis[pos[n_id]] = true;
                        q.push(pos[n_id]);
                    }
                    else if(pos[n_id] == -1 && !vis[n_id])
                    {   //不是梯子
                        vis[n_id] = true;
                        q.push(n_id);
                    }
                }
            }
            step++;
        }
        return -1;
    }
};