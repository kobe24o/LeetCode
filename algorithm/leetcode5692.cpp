class Solution {
public:
    vector<double> getCollisionTimes(vector<vector<int>>& cars) {
        int n = cars.size();
        vector<double> ans(n, -1.0);
        stack<int> s;
        for(int i = n-1; i >= 0; i--) 
        {
            while(!s.empty() && (cars[s.top()][1] >= cars[i][1] || (ans[s.top()] > 0 && delta(cars, i, s.top()) > ans[s.top()])))
            {   // 我的速度没有前车大，追不上前面的，检查再前面的人，前面可能有更慢的
                //前车 top 能撞上别人 且 撞上别人的时间 小于 我撞上top的时间，那我应该去跟更前面的人计算
                // 因为前车 top 已经先于我 撞上更前面的
                s.pop();
            }
            if(!s.empty())
                ans[i] = delta(cars, i, s.top());
            s.push(i);
        }
        return ans;
    }
    double delta(vector<vector<int>>& cars, int i, int j)//j 位置远，速度慢
    {
        return (cars[j][0] - cars[i][0])/double(cars[i][1] - cars[j][1]);
    }
};