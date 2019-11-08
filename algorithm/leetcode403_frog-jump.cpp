#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
public:
    bool canCross(vector<int>& stones) {
        unordered_map<int,int> m;//存储val、下标
        int i, j, k, n = stones.size(), m;
        if(stones[1] != 1)
            return false;
        for(i = 0; i < n; ++i) 
        	m[stones[i]] = i;
        // int dp[n] = {0};//存储到达一块石头时，一次跨多少步过来的
        vector<vector<int>> dp(n,{});//可能有多种跳到过来的方法，对后面的k有影响
        // memset(dp,0,n*sizeof(int));
        dp[1].push_back(stones[1]-stones[0]);
        int delta[3] = {-1,0,1};
        int distance, step;
        for(i = 1; i < n; ++i)
        {
        	m = dp[i].size();
            if(m > 0)
            {
                for(j = 0; j < 3; ++j)
                {
                	for(k = 0; k < m; ++k)
                	{
	                	step = dp[i][k]+delta[j];
	                	distance = stones[i]+step;
	                    if(step > 0 && m.count(distance))
	                        dp[m[distance]].push_back(dp[i]+delta[j]);
	                }
                }
            }
        }
        return dp[n-1]>0;
    }
};
int main()
{
	Solution s;
	vector<int> v = {0,1,3,5,6,8,12,17};
	s.canCross(v);
}