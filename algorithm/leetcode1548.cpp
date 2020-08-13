class Solution {
public:
    vector<int> mostSimilar(int n, vector<vector<int>>& roads, vector<string>& names, vector<string>& targetPath) {
        vector<vector<int>> g(n);
        for(auto& r : roads)
        {
            g[r[0]].push_back(r[1]);
            g[r[1]].push_back(r[0]);
        }
        int len = targetPath.size();
        vector<vector<int>> dp(len, vector<int>(n, INT_MAX));
        vector<vector<int>> path1(n);//n个城市作为起点的路线
        vector<vector<int>> path2(n);//存储下一个状态的路径
        for(int i = 0; i < n; ++i)//初始化
        {
            dp[0][i] = (names[i] != targetPath[0]);
            path1[i].push_back(i);
        }
        int mindis = INT_MAX, minidx = -1;
        for(int k = 1;  k < len; ++k)
        {
            for(int i = 0; i < n; ++i)
            {
                if(dp[k-1][i] == INT_MAX)
                    continue;
                for(int j : g[i])
                {
                    if(dp[k][j] > dp[k-1][i]+(names[j]!=targetPath[k]))
                    {
                        dp[k][j] = dp[k-1][i]+(names[j]!=targetPath[k]);
                        path2[j] = path1[i];
                        path2[j].push_back(j);
                    }
                }
            }
            swap(path1, path2);
        }
        for(int i = 0; i < n; i++) 
        {
            if(mindis > dp[len-1][i])
            {
                mindis = dp[len-1][i];
                minidx = i;
            }
        }
        return path1[minidx];
    }
};