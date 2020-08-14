class Solution {
	int found = -1;
	int part;
public:
    bool makesquare(vector<int>& nums) {
    	int sum = accumulate(nums.begin(), nums.end(), 0);
    	if(sum%4 || nums.size() < 4) return false;
    	part = sum/4;
    	vector<bool> visited(nums.size(), false);
        sort(nums.rbegin(), nums.rend());
        if(nums[0]<part && nums[0]+nums.back() > part)
            return false;
    	bt(nums, visited, 0, 0);
    	return found==1;
    }
    void bt(vector<int>& nums, vector<bool>& visited, int s, int count)
    {
    	if(s > part || found==0 || found ==1) return;
        if(count==4)
        {
            found = 1;
            return;
        }
    	for(int i = 0; i < nums.size(); ++i)
    	{
    		if(visited[i])
    			continue;
            if(nums[i] > part)
            {
                found = 0;
                return;
            }
    		visited[i] = true;
    		s += nums[i];
            bool flag = s==part;
            if(flag)
            {
                count++;
                s = 0;
            }
    		bt(nums, visited, s, count);
            if(flag)
            {
                count--;
                s = part;
            }
    		s -= nums[i];
    		visited[i] = false;
    	}
    }
};