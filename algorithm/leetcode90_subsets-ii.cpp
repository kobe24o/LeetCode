#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> sub;
        vector<vector<int>> ans;
        ans.push_back({});
        bt(nums,sub,ans,0);
        return ans;
    }
    void bt(vector<int>& nums,vector<int> sub, vector<vector<int>> &ans, int i)
    {
        for(int idx = i; idx < nums.size(); ++idx)
        {
            if(idx > i && nums[idx] == nums[idx-1])
                continue;
            sub.push_back(nums[idx]);
            ans.push_back(sub);
            bt(nums,sub,ans,idx+1);
            sub.pop_back();
        }
    }
};
int main()
{
    vector<int> nums = {1,2,2};
    Solution s;
    s.subsetsWithDup(nums);
}

// class Solution {
// public:
//     vector<vector<int>> subsetsWithDup(vector<int>& nums) {
//         vector<int> sub;
//         vector<vector<int>> ans;
//         ans.push_back({});
//         sort(nums.begin(), nums.end());
//         int i, j, left = 0, right;
//         for(i = 0; i < nums.size(); ++i)
//         {
//             if(i != 0 && (nums[i-1] != nums[i]))
//                 left = 0;
//             right = ans.size();
//             for(j = left; j < right; ++j)
//             {
//                 sub = ans[j];
//                 sub.push_back(nums[i]);
//                 ans.push_back(sub);
//             }
//             left = ans.size()-(right-left);
//         }
//         return ans;
//     }
// };