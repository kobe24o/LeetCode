class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
    	int count = 0;
        bt(0,0,nums,S,count);
        return count;
    }
    void bt(int i, int cursum, vector<int>& nums, int &S, int &count) 
    {
    	if(i == nums.size())
    	{
    		if(cursum == S)
    			++count;
    		return;
    	}
    	bt(i+1,cursum+nums[i],nums,S,count);
    	bt(i+1,cursum-nums[i],nums,S,count);
    }
};

class Solution {//超时
public:
    int findTargetSumWays(vector<int>& nums, int S) {
    	int count = 0, n, lv = 0;
    	queue<int> q;
    	q.push(0);
    	while(!q.empty())
    	{
    		n = q.size();
    		while(n--)
    		{
    			if(lv == nums.size() && q.front()==S)
    			{
    				++count;
    			}
    			q.push(q.front()+nums[lv]);
    			q.push(q.front()-nums[lv]);
    			q.pop();
    		}
    		lv++;
    		if(lv == nums.size())
    			break;
    	}
    	return count;
    }
};

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        int i, j, sum_nums = 0;
        for(i = 0; i < nums.size(); ++i)
        	sum_nums += nums[i];
        if((sum_nums+S)%2 != 0)
        	return 0;
        S = (S+sum_nums)>>1;
        int *dp = new int [S+1];
        memset(dp,0,(S+1)*sizeof(int));
        dp[0] = 1;
        for(i = 0; i < nums.size(); ++i)
        {
        	for(j = S; j >= 0; --j)
        	{
        		if(dp[j] != 0 && j+nums[i] <= S)
        			dp[j+nums[i]] += dp[j];
        	}
        }
        return dp[S];
    }
};