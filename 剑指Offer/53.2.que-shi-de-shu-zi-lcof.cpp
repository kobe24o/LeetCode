class Solution {
public:
    int missingNumber(vector<int>& nums) {
        for(int i = 0; i < nums.size(); ++i)
        	if(nums[i] != i)
        		return i;
    	return nums.size();//有个例子是 [0],答案预期 1
    }
};

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int i, ans = nums.size();
        for(i = 0; i < nums.size(); ++i)
        	ans = ans^i^nums[i];
        return ans;
    }
};

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int l = 0, r = nums.size()-1, mid;
        while(l < r)
        {
        	mid = l+((r-l)>>1);
        	if(nums[mid] == mid)//左边都不缺
        		l = mid+1;
        	else//不相等，左边肯定缺了东西，可能在当前位置
        		r = mid;
        }
        if(nums[l] == l)//全部有序，前面全部不缺
        	return l+1;
        return l;
    }
};