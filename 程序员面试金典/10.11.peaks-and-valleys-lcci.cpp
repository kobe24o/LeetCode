class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        sort(nums.rbegin(), nums.rend());
        int i = 1, j = nums.size()-1;
        while(i < j)
        {
        	swap(nums[i], nums[i+1]);
        	i += 2;
        }
    }
};
class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        for(int i = 1; i < nums.size(); ++i)
        {
        	if((i&1))//奇数位，定义为谷
        	{
        		if(nums[i] > nums[i-1])
        			swap(nums[i], nums[i-1]);
        	}
        	else//峰
        	{
        		if(nums[i] < nums[i-1])
        			swap(nums[i], nums[i-1]);
        	}
        }
    }
};