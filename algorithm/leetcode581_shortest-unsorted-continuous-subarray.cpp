class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> sorted(nums);
        sort(sorted.begin(), sorted.end());
        int i = nums.size()-1, j = 0;
        for(int k = 0; k < nums.size(); ++k)
        {
        	if(nums[k] != sorted[k])
        	{
        		i = min(i,k);
        		j = max(j,k);
        	}
        }
        if(j > i)
        	return j-i+1;
        return 0;
    }
};

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        if(nums.size() <= 1)
            return 0;
        int i, MIN = INT_MAX, MAX = INT_MIN;
        bool flag = false;
        for(i = 1; i < nums.size(); ++i)
        {
        	if(nums[i-1] > nums[i])
        		flag = true;
        	if(flag)
        		MIN = min(MIN,nums[i]);//找拐点后面的最小值
        }
        flag = false;
        for(i = nums.size()-2; i >= 0; --i)
        {
        	if(nums[i] > nums[i+1])
        		flag = true;
        	if(flag)
        		MAX = max(MAX,nums[i]);//找拐点前面的最大值
        }
        int l,r;
        for(l = 0; l < nums.size(); ++l)
        	if(MIN < nums[l])//最小值插入位置
        		break;
    	for(r = nums.size()-1; r >= 0; --r)
    		if(MAX > nums[r])//最大值插入的位置
    			break;
		if(r > l)
			return r-l+1;
		return 0;
    }
};

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int i, l = nums.size()-1, r = 0, idx;
        stack<int> stk;//存放下标
        for(i = 0; i < nums.size(); ++i)
        {
        	if(stk.empty() || nums[i] >= nums[stk.top()])
        		stk.push(i);
        	else
        	{
        		while(!stk.empty() && nums[stk.top()] > nums[i])
        		{
        			idx = stk.top();
        			stk.pop();
        		}
        		l = min(l,idx);
        	}
        }
        while(!stk.empty())
        	stk.pop();
        for(i = nums.size()-1; i >= 0; --i)
        {
        	if(stk.empty() || nums[i] <= nums[stk.top()])
        		stk.push(i);
        	else
        	{
        		while(!stk.empty() && nums[stk.top()] < nums[i])
        		{
        			idx = stk.top();
        			stk.pop();
        		}
        		r = max(r,idx);
        	}
        }
        if(r>l)
        	return r-l+1;
        return 0;
    }
};