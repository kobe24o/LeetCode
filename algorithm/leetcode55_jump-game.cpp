class Solution {
public:
    bool canJump(vector<int>& nums) {
         int maxS = 0, i;
         for(i = 0; i < nums.size(); ++i)
         {
         	if(maxS < i)
         		return false;
         	maxS = max(maxS, nums[i]+i);
         }
         return true;
    }
};