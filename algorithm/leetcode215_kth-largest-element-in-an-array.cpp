class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        k = nums.size()-k;
        return findKthL(nums,k,0,nums.size()-1);
    }
private:
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

    int findKthL(vector<int>& nums, int &k, int left, int right)
    {
        selectMid(nums,left,right);//三数取中
        int p = nums[left];
        int i = left, j = right;
        while(i < j)
        {
            while(i < j && nums[j] > p)
                j--;
            swap(nums[i], nums[j]);
            while(i < j && nums[i] <= p)
                i++;
            swap(nums[i], nums[j]);
        }
        if(i == k)
            return nums[i];
        else if(i < k)
            return findKthL(nums,k,i+1,right);
        else
            return findKthL(nums,k,left,i-1);
    }
};