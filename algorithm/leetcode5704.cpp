class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> right(n,-1), left(n,-1);
        stack<int> s;
        for(int i = n-1; i >= 0; i--)
        {
            while(!s.empty() && nums[s.top()] >= nums[i])
                s.pop();
            if(!s.empty())
                right[i] = s.top()-1;
            else
                right[i] = n-1;
            s.push(i);
        }
        while(!s.empty()) s.pop();
        for(int i = 0; i < n; i++)
        {
            while(!s.empty() && nums[s.top()] >= nums[i])
                s.pop();
            if(!s.empty())
                left[i] = s.top()+1;
            else
                left[i] = 0;
            s.push(i);
        }
        int maxScore = 0;
        for(int i = 0; i < n; i++)
            if(left[i] <= k && k <= right[i])
                maxScore = max(maxScore, nums[i]*(right[i]-left[i]+1));
        return maxScore;
    }
};