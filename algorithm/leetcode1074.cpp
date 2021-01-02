class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> presum(m+1, vector<int>(n+1, 0));
        for(int i = 1; i <= m; i++) 
        {
            for(int j = 1; j <= n; j++)
            {
                presum[i][j] = matrix[i-1][j-1]+presum[i-1][j]+presum[i][j-1]-presum[i-1][j-1];
            }
        }// 左上角 [0,0] 到 右下角[i,j] 的 前缀和
        int ans = 0;
        for(int i1 = 1; i1 <= m; i1++)
        {
            for(int i2 = i1; i2 <= m; i2++)
            {   //枚举两个顶点的 行的 idx 组合
                unordered_map<int,int> map; // 和，计数
                for(int j = 1; j <= n; j++)
                {
                    int sum = presum[i2][j]-presum[i1-1][j];
                    if(sum == target)
                        ans++;
                    if(map.find(sum-target) != map.end())
                    {
                        ans += map[sum-target];
                    }
                    map[sum]++;
                }
            }
        }
        return ans;
    }
};