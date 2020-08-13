class Solution {
public:
    bool makesquare(vector<int>& nums) {
    	int sum = accumulate(nums.begin(), nums.end(), 0);
    	if(sum%4) return false;
    	
    }
};