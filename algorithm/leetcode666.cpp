class Solution {
	unordered_map<int,int> m;//id,val
	int sum = 0;
public:
    int pathSum(vector<int>& nums) {
    	if(nums.empty()) return 0;
    	for(int i = 0; i < nums.size(); ++i)
    	{
    		int pos = (1<<(nums[i]/100 -1)) + nums[i]/10%10 -1;
    		m[pos] = nums[i]%10;
    	}
    	dfs(1, 0);//从root编号1，s 为和0开始dfs
    	return sum;
    }
    void dfs(int p, int s)
    {
    	if(!m.count(p))
    		return;
        s += m[p];
    	bool l = m.count(2*p), r = m.count(2*p+1);
    	if(!l && !r)
    	{
    		sum += s;
    		return;
    	}
    	dfs(2*p, s);
    	dfs(2*p+1, s);
    }
};