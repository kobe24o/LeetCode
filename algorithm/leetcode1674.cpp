class Solution {
public:
    int minMoves(vector<int>& nums, int limit) {
        int n = nums.size();
        vector<int> delta(2*limit+2, 0);
        //差分数组
        for(int i = 0; i < n/2; i++)
        {
            int a = min(nums[i], nums[n-1-i]);
            int b = max(nums[i], nums[n-1-i]);
            delta[2] += 2;
            delta[1+a]--;
            delta[a+b]--;
            delta[a+b+1]++;
            delta[b+1+limit]++;
        }
        int presum = 0, ans = n;
        for(int i = 2; i <= 2*limit; ++i) 
        {
            presum += delta[i];
            ans = min(ans, presum);
        }
        return ans;
    }
};