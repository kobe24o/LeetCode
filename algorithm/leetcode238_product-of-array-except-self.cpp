class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans(nums.size(),1);
        int i, temp = 1;
        for(i = 1; i < nums.size(); ++i)
        {
        	ans[i] = ans[i-1]*nums[i-1];//ans存放num[i]左边的乘积
        }
        for(i = nums.size()-2; i >= 0; --i)
        {	//乘以右边的乘积
        	temp *= nums[i+1];//temp是右边的乘积
        	ans[i] *= temp;//左右乘积相乘
        }
        return ans;
    }
};