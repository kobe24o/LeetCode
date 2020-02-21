/**
 * @description: 调试使用
 * @author: michael ming
 * @date: 2019/11/24 22:55
 * @modified by: 
 */
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if(nums.empty())
            return {};
        int l = 1, r = 0;
        vector<int> ans;
        deque<int> q;
        while(k--)
        {
            while(!q.empty() && nums[q.back()] <= nums[r])
            {
                q.pop_back();
            }
            q.push_back(r++);
        }
        ans.push_back(nums[q.front()]);
        while(r < nums.size())
        {
            if(q.front() < l)
                q.pop_front();
            while(!q.empty() && nums[q.back()] <= nums[r])
            {
                q.pop_back();
            }
            q.push_back(r++);
            l++;
            ans.push_back(nums[q.front()]);
        }
        return ans;
    }
};
int main()
{
    Solution s;
    vector<int> v = {1,3,1,2,0,5};
    s.maxSlidingWindow(v,3);

}