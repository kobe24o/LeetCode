const int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, -1, 0, 1};
const int INF = 0x3f3f3f3f;

class Solution {
public:
    int minimalSteps(vector<string>& maze) {
        int n = maze.size(), m = maze[0].size();
        int si, sj, ti, tj;
        vector<pair<int, int>> keys, locks;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j) {
                // 记录特殊位置的信息（起点、终点、机关、石头）
                if (maze[i][j] == 'M')
                    locks.emplace_back(i, j);
                if (maze[i][j] == 'S') {
                    si = i;
                    sj = j;
                }
                if (maze[i][j] == 'T') {
                    ti = i;
                    tj = j;
                }
                if (maze[i][j] == 'O')
                    keys.emplace_back(i, j);
            }
        
        // 把起点也当成机关，避免特殊讨论
        locks.insert(locks.begin(), {si, sj});
        int nk = keys.size(), nl = locks.size();
        // tdist记录终点到所有点的距离
        vector<int> tdist(n * m, INF);
        // kdist记录每一块石头到所有点的距离
        vector<vector<int>> kdist(nk, vector<int>(n * m, INF));
        // 公共的BFS函数
        auto bfs = [&](int ui, int uj, vector<int> &dist){
            queue<pair<int, int>> q;
            vector<bool> vis(n * m);
            q.push({ui, uj});
            dist[ui * m + uj] = 0;
            vis[ui * m + uj] = true;
            while (!q.empty()) {
                auto front = q.front();
                auto [i, j] = front;
                q.pop();
                for (int k = 0; k < 4; ++k) {
                    int ni = i + dy[k], nj = j + dx[k];
                    if (ni < 0 || ni >= n || nj < 0 || nj >= m || vis[ni * m + nj] || maze[ni][nj] == '#')
                        continue;
                    dist[ni * m + nj] = dist[i * m + j] + 1;
                    vis[ni * m + nj] = true;
                    q.push({ni, nj});
                }
            }
        };
        for (int i = 0; i < nk; ++i)
            bfs(keys[i].first, keys[i].second, kdist[i]);
        bfs(ti, tj, tdist);
        
        // 利用求出的kdist，求解任意两个机关（包括起点）之间的最短距离
        vector<vector<int>> ldist(nl, vector<int>(nl, INF));
        for (int i = 0; i < nl; ++i) {
            int iidx = locks[i].first * m + locks[i].second;
            for (int j = 0; j < nl; ++j) {
                if (i == j)
                    continue;
                int jidx = locks[j].first * m + locks[j].second;
                for (int k = 0; k < nk; ++k) {
                    ldist[i][j] = min(ldist[i][j], kdist[k][iidx] + kdist[k][jidx]);
                }
            }
        }
        
        // DP数组初始化。开始时，位于0号机关（也即起点），对应二进制状态为1（只有0号机关打开）
        vector<vector<int>> dp(nl, vector<int>(1 << nl, INF));
        dp[0][1] = 0;
        for (int state = 1; state < (1 << nl); ++state) {
            for (int curr = 0; curr < nl; ++curr) {
                // 当前状态不可达
                if (dp[curr][state] == INF)
                    continue;
                // 下一步要打开的机关
                for (int i = 1; i < nl; ++i) {
                    // 目标机关已经打开
                    if (state & (1 << i))
                        continue;
                    // 目标机关还未被打开，更新最优解
                    int nxt = state + (1 << i);
                    dp[i][nxt] = min(dp[i][nxt], dp[curr][state] + ldist[curr][i]);
                }
            }
        }
        // 出发去终点前的状态，应当是处于某一机关处，同时所有机关均已打开。
        // 遍历所有机关的位置，得到最终的结果。
        int ans = INF;
        for (int i = 0; i < nl; ++i)
            ans = min(ans, dp[i][(1 << nl) - 1] + tdist[locks[i].first * m + locks[i].second]);
        // 如果不存在可行解，输出-1。
        return ans == INF ? -1 : ans;
    }
};

// 参考：https://leetcode-cn.com/problems/xun-bao/solution/bfszhuang-tai-ya-suo-dp-by-lucifer1004/
