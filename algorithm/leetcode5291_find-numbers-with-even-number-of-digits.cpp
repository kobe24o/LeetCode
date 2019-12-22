class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int i, n, ans = 0;
        for(i = 0; i < nums.size(); i++)
        {
        	n = 0;
        	while(nums[i])
        	{
        		n++;
        		nums[i] /= 10;
        	}
        	if((n&1) == 0)
        		ans++;
        }
        return ans;
    }
};