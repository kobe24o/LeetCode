class Solution {
public:
    int minAbsDifference(vector<int>& nums, int goal) {
        int n = nums.size();
        vector<int> arr1, arr2;
        getsum(nums, 0, n/2, arr1);
        getsum(nums, n/2, n, arr2);
        int i = 0, j = arr2.size()-1, n1 = arr1.size();
        int diff = INT_MAX, sum;
        while(i < n1 && j >= 0)
        {
            sum = arr1[i] + arr2[j];
            diff = min(diff, abs(sum-goal));
            if(sum > goal)
                j--;
            else if(sum < goal)
                i++;
            else
                break;
        }
        return diff;
    }
    void getsum(vector<int>& nums, int l, int r, vector<int>& arr)
    {
        int n = r-l;
        arr.resize(1<<n);
        for(int i = 0; i < (1<<n); i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(i & (1 << j))
                    continue;// i 状态 包含 j 数字
                arr[i+(1<<j)] = arr[i] + nums[l+j];
            }
        }
        sort(arr.begin(), arr.end());
    }
};