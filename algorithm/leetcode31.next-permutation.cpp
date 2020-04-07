class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if(nums.empty() <= 1)
            return;
        int i = nums.size()-2, j = nums.size()-1, k, n = nums.size();
        while(i >= 0 && nums[i] >= nums[j])
            i--;j--;
        if(i>=0)
        {
            k = i;
            while(j < n && nums[i] < nums[j])
                j++;
            swap(nums[i], nums[j-1]);   
        }
        sort(nums.begin()+i+1,nums.end());
    }
};