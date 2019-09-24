class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int left = INT_MAX;
        int right = INT_MAX;        
        for (int i = 0; i < nums.size();++i) 
        {
            if (nums[i] <= left)
                left = nums[i];
            else if (nums[i] <= right) 
                right = nums[i];
            else
                return true;
        }     
        return false;
    }
};
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        if(nums.size() < 3)
        	return false;
        int dpmin[nums.size()], dpmax[nums.size()], temp;
        temp = INT_MAX;
        for(int i = 0; i < nums.size(); ++i)
        	if(nums[i] <= temp)
        	{
        		dpmin[i] = i;
        		temp = nums[i];
        	}
        	else
        		dpmin[i] = dpmin[i-1];
    	temp = INT_MIN;
        for(int i = nums.size()-1; i >= 0; --i)
        	if(nums[i] >= temp)
        	{
        		dpmax[i] = i;
        		temp = nums[i];
        	}
        	else
        		dpmax[i] = dpmax[i+1];
        for(int i = 0; i < nums.size(); ++i)
        	if(i > dpmin[i] && i < dpmax[i])
        		return true;
    	return false;
    }
};