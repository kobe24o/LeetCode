class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        int sum = 0;
        m[0] = -1;
        for(int i = 0; i < nums.size(); ++i)
        {
        	sum += nums[i];
        	if(k != 0)
        		sum = sum%k;
    		if(m.find(sum) != m.end())
    		{
    			if(i-m[sum] > 1)
    				return true;
    		}
			else
    			m[sum] = i;
        }
        return false;
    }
};