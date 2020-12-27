typedef pair<int,int> pii;
struct cmp
{
    bool operator()(pii& a, pii& b) const
    {
        return a.first > b.first;//小的，先过期的优先吃
    }
};
class Solution {
public:
    int eatenApples(vector<int>& apples, vector<int>& days) {
        priority_queue<pii,vector<pii>, cmp> q;//pair 过期时间，剩余的果子数量
        int eat = 0, n = apples.size();
        for(int i = 0; i < n || !q.empty(); i++) 
        {
            while(!q.empty() && q.top().first==i)//苹果过期了，删除
                q.pop();
            if(i < n && apples[i] > 0)//当前的苹果加入优先队列
                q.push({i+days[i], apples[i]});
            if(!q.empty())
            {
                pii t = q.top();
                q.pop();
                eat++;//吃一个
                if(--t.second > 0)//这一堆还没吃完
                    q.push(t);
            }
        }
        return eat;
    }
};