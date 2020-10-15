typedef pair<int,pair<int,int>> piii;
struct cmp{
    bool operator()(piii& a, piii& b) const
    {
        return a.first > b.first;//价格低的优先
    }
};
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        vector<unordered_map<int,int>> g(n);
        for(auto& f : flights)
        {
            g[f[0]][f[1]] = f[2];
        }
        K++;//可以走K+1步
        vector<vector<int>> price(n, vector<int>(K+1,INT_MAX));
        price[src][0] = 0;//在某点，走了几步的最少花费
        priority_queue<piii,vector<piii>,cmp> q;
        q.push({0, {src, 0}});//路径机票价格总和, 当前点，走了几步
        int id, money, ntid, cost, step;
        while(!q.empty())
        {
            money = q.top().first;//之前总的花费
            id = q.top().second.first;//当前点
            step = q.top().second.second;//到这走了几步
            if(id == dst)//找到目标
                return price[id][step];
            q.pop();
            for(auto it = g[id].begin(); it != g[id].end(); ++it)
            {
                ntid = it->first;//下一个点
                cost = it->second;//需要的花费
                if(step+1 <= K && money+cost < price[ntid][step+1])
                {   //步数还可以走 && 花费较小
                    price[ntid][step+1] = money+cost;
                    q.push({money+cost, {ntid, step+1}});
                }
            }
        }
        return -1;
    }
};