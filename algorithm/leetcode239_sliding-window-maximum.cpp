#include <deque>
#include <vector>
#include <climits>

using namespace std;
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if(nums.size() == 0)
            return {};
        deque<int> q;
        vector<int> ans;
        int i;
        for(i = 0; i < k; ++i)
        {
            while(!q.empty() && nums[i] >= nums[q.back()])
            {
                q.pop_back();// <=nums[i]的前面的存的，无意义，删掉
            }
            q.push_back(i);
        }
        ans.push_back(nums[q.front()]);
        for(i = k; i < nums.size(); ++i)
        {
            if(!q.empty() && i-k+1 > q.front())
                q.pop_front();//过了窗口了，删除
            while(!q.empty() && nums[i] >= nums[q.back()])
            {
                q.pop_back();
            }
            q.push_back(i);
            ans.push_back(nums[q.front()]);
        }
        return ans;
    }
};
int main()
{
    Solution s;
    vector<int> vec = {1,3,-1,-3,5,3,6,7};
    s.maxSlidingWindow(vec,3);
}