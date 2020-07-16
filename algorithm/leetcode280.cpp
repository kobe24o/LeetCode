class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        for(int i = 0; i < int(nums.size())-1; ++i)
        {
        	if(i%2==0 && nums[i] > nums[i+1])
        		swap(nums[i], nums[i+1]);
    		else if(i%2==1 && nums[i] < nums[i+1])
    			swap(nums[i], nums[i+1]);
        }
    }
};