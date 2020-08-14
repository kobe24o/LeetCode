class Solution {
	bool found = false;
	int part, count = 0;
public:
    bool makesquare(vector<int>& nums) {
    	int sum = accumulate(nums.begin(), nums.end(), 0);
    	if(sum%4) return false;
    	part = sum/4;
    	vector<bool> visited(nums.size(), false);
    	bt(nums, visited, 0);
    	return found;
    }
    void bt(vector<int>& nums, vector<bool>& visited, int s)
    {
    	if(s > part || found) return;
    	if(s == part)
    	{
    		count++;
    		s = 0;
    		if(count==4)
    		{
    			found = true;
    			return;
    		}
    	}
    	for(int i = 0; i < nums.size(); ++i)
    	{
    		if(visited[i])
    			continue;
    		visited[i] = true;
    		s += nums[i];
    		bt(nums, visited, s);
    		s -= nums[i];
    		visited[i] = false;
    	}
        if(s == 0)
    	{
            count--;
            s = part;
        }
    }
};