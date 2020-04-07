class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if(nums.size() <= 1)
            return;
        int i = nums.size()-2, j, n = nums.size();
        while(i >= 0 && nums[i] >= nums[i+1])
            i--;//找下降点
        if(i>=0)
        {
            j = i+1;
            while(j < n && nums[i] < nums[j])
                j++;//找比 i 点大的，最小点
            swap(nums[i], nums[j-1]);   
        }
        reverse(nums,i+1,n-1);//反转 i+1, end
    }

    inline void reverse(vector<int>& a, int l, int r)
    {
        while(l < r)
            swap(a[l++],a[r--]);
    }
};