class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        int i = 0, len = nums.size(), ans = 0;
        // [1, v) 区间 加上 v 就可以表示 [1, 2v), 右端点用 v 来表示
        // [1, v) 区间 加上 k 就可以表示 [1, v+k), 右端点用 v 来表示
        long long v = 1;
        while(v <= n)
        {
            if(i < len && nums[i] <= v)
                v += nums[i++];
            else// v < nums[i] , 右端点够不着 nums[i]，需要添加一个 v，区间变为[1,2v)
            {
                v += v;
                ans++;
            }
        }
        return ans;
    }
};