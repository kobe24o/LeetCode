class Solution {
public:
    int findMin(vector<int>& nums) {
        int L = 0, R = nums.size()-1, mid;
        if(nums[L] <= nums[R])//一个元素或者升序的情况
        	return nums[L];
        while(L <= R)
        {
        	mid = L+((R-L)>>1);
        	//--------------------------
            if(nums[mid] > nums[mid+1])
        		return nums[mid+1];
        	if(nums[mid-1] > nums[mid])
        		return nums[mid];
        	//两个if不能换顺序，防止mid-1越界
        	//--------------------------
        	if(nums[L] <= nums[mid])//左边有序
        		L = mid+1;
        	else	//右边有序
        		R = mid-1;
        }
        return -1;
    }
};