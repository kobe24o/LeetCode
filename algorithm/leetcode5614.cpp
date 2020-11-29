class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        int n = nums.size();
        if(n == k)
            return nums;
        deque<int> q;
        for(int i = 0; i < n; ++i)
        {
            while(!q.empty() && q.size()+n-i > k && q.back() > nums[i])
                q.pop_back();
            q.push_back(nums[i]);
        }
        return vector<int>(q.begin(), q.begin()+k);
    }
};