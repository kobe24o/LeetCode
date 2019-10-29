class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
    	int n = nums.size(), i = 0, j = n-1;
    	while(i < j && nums[i] <= nums[i+1])
    		i++;
    	while(i < j && nums[j-1] <= nums[j])
    		j--;
    	//i,j停下的地方可能不满足非降

    	int leftMax =  i == 0 ? INT_MIN : nums[i-1];
    	int rightMin =  j == n-1 ? INT_MAX : nums[j+1];
    	if(j-i <= 1 && (leftMax <= nums[j] || nums[i] <= rightMin))
        	return true;
        return false;
    }
};