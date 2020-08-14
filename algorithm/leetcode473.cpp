class Solution {
	bool found = false;
	int s1_4;
	vector<int> parts;
public:
    bool makesquare(vector<int>& nums) {
        sort(nums.rbegin(), nums.rend());
    	int sum = accumulate(nums.begin(), nums.end(), 0);
        s1_4 = sum/4;
        parts = vector<int> (4,0);
    	if(sum%4 || nums.size() < 4 || nums[0] > s1_4) return false;
        if(nums[0] < s1_4 && nums[0]+nums.back() > s1_4)
        //都小于1/4，且最大+最小 > 1/4 
            return false;
    	bt(nums, 0);
    	return found;
    }
    void bt(vector<int>& nums, int idx)
    {
    	if(found) return;
    	if(parts[0] > s1_4 || parts[1] > s1_4
    		|| parts[2] > s1_4 || parts[3] > s1_4)
    		return;
        if(idx==nums.size() && parts[0]==parts[1] 
                && parts[0]==parts[2] && parts[0]==parts[3])
        {
            found = true;
            return;
        }
    	for(int i = 0; i < 4; ++i)
    	{
    		parts[i] += nums[idx];
    		bt(nums, idx+1);
    		parts[i] -= nums[idx];
    	}
    }
};