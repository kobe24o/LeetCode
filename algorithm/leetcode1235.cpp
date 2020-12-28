- 先按照结束时间排序
- dp 是map，key 是结束时间，value 是 到结束时间 key 时的最大的收益
- 每次二分查找 map 找到上一个不冲突的结束时间点，进行状态转移
```cpp
class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        vector<int> id(n);
        iota(id.begin(), id.end(), 0);// 生成序列 0,1，2，。。。
        sort(id.begin(), id.end(),[&](auto a, auto b){
            return endTime[a] < endTime[b];//按结束时间排序
        });
        map<int,int> dp;
        dp[0] = 0;//边界
        dp[endTime[id[0]]] = profit[id[0]];//第一个状态
        int ans = profit[id[0]];
        for(int i = 1; i < n; i++)
        {
            int idx = id[i];//序号
            auto it = dp.upper_bound(startTime[idx]);//这次任务之前的不冲突任务时间点
            int dp_prev = (--it)->second;//上一个不冲突结束时间点的最大收益
            dp[endTime[idx]] = max(ans, max(dp[endTime[idx]], dp_prev+profit[idx]));
            ans = max(ans, dp[endTime[idx]]);
        }
        return ans;
    }
};
```
600 ms  51.9 MB C++


---

我的CSDN[博客地址 https://michael.blog.csdn.net/](https://michael.blog.csdn.net/)

长按或扫码关注我的公众号（Michael阿明），一起加油、一起学习进步！
