class Solution {
public:
    bool canCross(vector<int>& stones) {
        unordered_map<int,int> m;//存储distance、对应的下标
        int i, j, k, n = stones.size(), len;
        if(stones[1] != 1)//题目意思是，第一步只能走1个distance
            return false;
        for(i = 0; i < n; ++i) 
        	m[stones[i]] = i;
        // int dp[n] = {0};//存储到达一块石头时，一次跨多少步过来的（不可以用一维数组）
        vector<unordered_set<int>> dp(n);//可能有多种跳到过来的方法，对后面的k有影响
        unordered_set<int>::iterator it;
        dp[1].insert(1);
        int delta[3] = {-1,0,1};//前进的增量
        int distance, step;
        for(i = 1; i < n; ++i)
        {
        	len = dp[i].size();
            if(len > 0)//跳过来的方案数存在
            {
                for(j = 0; j < 3; ++j)//每个方案有3种增量前进
                {
                	for(it = dp[i].begin(); it != dp[i].end(); ++it)
                	{	//遍历每个方案（前面多少步跳过来的）
	                	step = *it+delta[j];
	                	distance = stones[i]+step;//可到的距离
	                    if(step > 0 && m.count(distance))//方向是向前的，且 在石头上
	                        dp[m[distance]].insert(step);//将多少步过去的记录在那个石头上
	                }
                }
            }
        }
        return dp[n-1].size()>0;//有方案可以到达最后一个石头
    }
};