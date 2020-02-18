class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return nums[nums.size()/2];
    }
};

class Solution {//摩尔投票
public:
    int majorityElement(vector<int>& nums) {
        int i, maj, count = 0, n = 0;
        for(i = 0; i < nums.size(); ++i)
        {
        	if(count == 0)
        	{
        		maj = nums[i];
        		count++;
        	}
        	else
        	{
        		if(maj == nums[i])
        			count++;
        		else
        			count--;
        	}
        }
        for(i = 0; i < nums.size(); ++i)
        {
        	if(maj == nums[i])
        		n++;
        }
        if(n > nums.size()/2)
        	return maj;
        return -1;
    }
};