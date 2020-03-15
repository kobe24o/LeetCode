class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        vector<vector<int>> people;
        int i, e, s;
        long long maxPerf = 0, speedsum = 0;
        for(i = 0; i < speed.size(); ++i)
        {
        	people.push_back({efficiency[i], speed[i]});
        }

        sort(people.rbegin(), people.rend());//按照效率从大到小排序
        priority_queue<int, vector<int>,greater<int>> q;//小顶堆
        for(i = 0; i < speed.size(); ++i)
        {
        	e = people[i][0];//效率
        	speedsum += people[i][1];//速度和
        	k--;//人数-1
        	q.push(people[i][1]);//速度队列，堆顶最小
        	if(k < 0)//人超过k人了
        	{
        		speedsum -= q.top();//速度小的删除
        		q.pop();
        	}
        	maxPerf = max(maxPerf, e*speedsum);//这里不要取模
        }
        return maxPerf%1000000007;
    }
};