class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        nums.erase(unique(nums.begin(), nums.end()), nums.end());//去除相邻的相等的
        if(nums.size() < 2)
        	return nums.size();
        int a, b, c, i, len = 2;
        for(i = 1; i < nums.size()-1; ++i)
        {
        	a = nums[i-1];
        	b = nums[i];
        	c = nums[i+1];
        	if(a<b && b>c)
        		++len;
        	else if(a>b && b<c)
        		++len;
        }
        return len;
    }
};

class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if(nums.size() < 2)
        	return nums.size();
        int up=1, down=1, i;
        for(i = 1; i < nums.size(); ++i)
        {
        	if(nums[i] > nums[i-1])
        		up = down+1;
        	else if(nums[i] < nums[i-1])
        		down = up+1;
        }
        return max(up,down);
    }
};