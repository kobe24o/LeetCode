class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> q;
        vector<int> ans;
        int i, maxnum = INT_MIN;
        auto it = q.begin();
        for(i = 0; i < k; ++i)
        {
            q.push(nums[i]);
            if(nums[i] > maxnum)
                maxnum = nums[i];
        }
        ans.push_back(maxnum);
        for(i = k; i < nums.size(); ++i)
        {
            
            q.push(nums[i]);
            q.erase(q.begin());
            for(it = q.begin(); it != q.end(); ++it)
            {
                maxnum = *it;
                if(*it > maxnum)
                    maxnum = *it;
            }
            ans.push_back(maxnum);
        }
        return ans;
    }
};