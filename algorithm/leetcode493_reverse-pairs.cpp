class Solution {
    int count = 0;
    int *temp;
public:
    int reversePairs(vector<int>& nums) {
        temp = new int[nums.size()];
        rp(nums,0,nums.size()-1);
        return count;
    }
    void rp(vector<int>& nums, int left, int right) 
    {
        if(left >= right)
            return;
        int mid = (left+right)/2;
        rp(nums,left,mid);
        rp(nums,mid+1,right);
        merge(nums,left,mid,right);
    }
    void merge(vector<int>& nums, int left, int mid, int right)
    {
        int i = left, j = mid+1, k;
        while(i <= mid && j <= right)
        {
            if((long)nums[i] > 2*long(nums[j]))
            {
                count += mid-i+1;
                j++;
            }
            else
                i++;
        }//先处理问题
        //下面再排序
        i = left, j = mid+1, k = left;
        while(i <= mid && j <= right)
        {
            if(nums[i] <= nums[j])
                temp[k++] = nums[i++];
            else
                temp[k++] = nums[j++];
        }
        while(i <= mid)
            temp[k++] = nums[i++];
        while(j <= right)
            temp[k++] = nums[j++];
        for(i = left; i <= right; ++i)
            nums[i] = temp[i];
    }
};