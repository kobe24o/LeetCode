class Solution {
public:
    int unhappyFriends(int n, vector<vector<int>>& preferences, vector<vector<int>>& pairs) {
        vector<vector<int>> g(n);
        for(auto& p : pairs)
        {
            g[p[0]].push_back(p[1]);
            g[p[1]].push_back(p[0]);
        }
        vector<vector<int>> rela(n,vector<int>(n, 0));//关系数值
        for(int i = 0, val; i < n; i++)
        {
            val = n;
            for(int id : preferences[i])
                rela[i][id] = val--;
        }

        int x,y,u,v,i;
        vector<int> unhappy(n, 0);
        for(x = 0, y; x < n; x++)//遍历每个人
        {
            y = g[x][0], u, v;
            for(i = 0; i < n-1; i++)
            {
                if(preferences[x][i] == y)
                    break;
                u = preferences[x][i];//y前面的人（条件1）
                v = g[u][0];// u , v 配对的人
                if(rela[u][x] > rela[u][v])//（条件2）
                    unhappy[x] = 1;
            }
        }
        return accumulate(unhappy.begin(), unhappy.end(),0);
    }
};