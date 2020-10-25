class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        vector<bool> ans(l.size(), false);
        for(int i = 0; i < l.size(); ++i)
        {
            int L = l[i], R = r[i];
            vector<int> arr(nums.begin()+L, nums.begin()+R+1);
            sort(arr.begin(), arr.end());
            int d = arr[1] - arr[0];
            bool flag = true;
            for(int j = 1; j < arr.size(); ++j)
            {
                if(arr[j] - arr[j-1] != d)
                {
                    flag = false;
                    break;
                }
            }
            if(flag)
                ans[i] = true;
        }
        return ans;
    }
};