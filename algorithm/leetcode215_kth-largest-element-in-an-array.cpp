#include<vector>
using namespace std;
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        return findKthLargest(nums,k,0,nums.size()-1);
    }

    void selectMid(vector<int>& nums, int left, int right)
    {
    	int mid = left+((right-left)>>1);
    	if(nums[mid] > nums[right])
    		swap(nums[mid],nums[right]);
    	if(nums[left] > nums[right])
        	swap(nums[left], nums[right]);
    	if(nums[mid] > nums[left])
        	swap(nums[mid], nums[left]);
    }

    int findKthLargest(vector<int>& nums, int &k, int left, int right)
    {
    	selectMid(nums,left,right);
    	int p = nums[left];
    	size_t pIndex = left, i = left, j = right;
    	while(i < j)
    	{
    		while(i < j && nums[j] > p)
    			j--;
    		swap(nums[i], nums[j]);
    		while(i < j && nums[i] <= p)
    			i++;
    		swap(nums[i], nums[j]);
    	}
    	pIndex = i;//哨兵下标
    	if(i+1 == k)
    		return nums[i];
    	else if(i+1 < k)
    		return findKthLargest(nums,k,i+1,right);
    	else
    		return findKthLargest(nums,k,left,i-1);
    }
};
int main()
{
	Solution s;
	int arr[] = {3,2,1,5,6,4};
	s.findKthLargest(arr,2);
}