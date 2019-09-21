class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int bit = 0, i, n1 = 0, n2 = 0;
        for(i = 0; i < nums.size(); ++i)
        	bit ^= nums[i];
        bit &= (-bit);
        for(i = 0; i < nums.size(); ++i)
        {
        	if((bit & nums[i]) == 0)//内层括号！！！不能少
        		n1 ^= nums[i];
        	else
        		n2 ^= nums[i];
        }
        return {n1, n2};
    }
};