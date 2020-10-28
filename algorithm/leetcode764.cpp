class Solution {
public:
    int orderOfLargestPlusSign(int N, vector<vector<int>>& mines) {
        vector<vector<int>> g(N, vector<int>(N, 1));
        for(auto& m : mines)
            g[m[0]][m[1]] = 0;
        vector<vector<int>> up(N, vector<int>(N, 0));//该方向上的连续1的个数
        vector<vector<int>> left(N, vector<int>(N, 0));
        vector<vector<int>> down(N, vector<int>(N, 0));
        vector<vector<int>> right(N, vector<int>(N, 0));
        for(int i = 0; i < N; i++)
        {
            for(int j = 0; j < N; j++)
            {
                if(g[i][j] == 0)
                    continue;
                left[i][j] = (j > 0 ? left[i][j-1] : 0) + 1;
                up[i][j] = (i > 0 ? up[i-1][j] : 0) + 1;
            }
        }
        for(int i = N-1; i >= 0; i--)
        {
            for(int j = N-1; j >= 0; j--)
            {
                if(g[i][j] == 0)
                    continue;
                right[i][j] = (j < N-1 ? right[i][j+1] : 0) + 1;
                down[i][j] = (i < N-1 ? down[i+1][j] : 0) + 1;
            }
        }
        int ans = 0;
        for(int i = 0; i < N; i++)
        {
            for(int j = 0; j < N; j++)
                ans = max(ans, min(left[i][j], min(right[i][j],min(up[i][j], down[i][j]))));
        }
        return ans;
    }
};