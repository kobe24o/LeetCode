class Solution {
public:
    vector<bool> canEat(vector<int>& candiesCount, vector<vector<int>>& q) {
        vector<long long> presum(candiesCount.size());
        for(int i = 0 ;i < candiesCount.size(); ++i)
            presum[i] = candiesCount[i];
        for(int i = 1; i < candiesCount.size(); i++) 
        {
            presum[i] += presum[i-1];//前缀和
        }
        int n = q.size();
        vector<bool> ans(n, false);
        for(int i = 0; i < n; i++)
        {
            int idx = q[i][0];// 要吃的类型
            int day = q[i][1];// 前面要吃多少天
            int eat = q[i][2];//每天最多吃多少
            long long l = (idx > 0 ? (presum[idx-1]+1) : 1), r = presum[idx];
            // l, r 需要吃到 [l, r] 这个范围内才行
            long long L = day*1LL+1, R = (day+1LL)*eat;
            // L, R 最少，最多能吃的范围
            // 两者有交集 即可
            if((l >= L && l <= R)||(r >= L && r <= R))
                ans[i] = true;
            else if((L >= l && L <= r)||(R >= l && R <= r))
                ans[i] = true;
        }
        return ans;
    }
};