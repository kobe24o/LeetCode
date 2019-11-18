class Solution {
public:
    int minMoves(vector<int>& nums) {
    	if(nums.size() < 2)
    		return 0;
        long MinNum = nums[0], sum = nums[0]; 
        int i, n = nums.size();
        for(i = 1; i < n; ++i)
        {
        	if(nums[i] < MinNum)
        		MinNum = nums[i];
        	sum += nums[i];
        }
        //(final-MinNum)*(n-1)+sum == n*final
        //final = sum-(n-1)*MinNum
        //final-MinNum = sum-n*MinNum
        return sum-n*MinNum;
    }
};