// class Solution {
// public:
//     vector<int> nextGreaterElements(vector<int>& nums) {
//         int n = nums.size(), i, j, count = 0;
//         bool found;
//         vector<int> ans;
//         for(int i = 0; i < n; i++)
//         {
//         	count = n-1;
//         	found = false;
//         	j = i+1;
//         	if(j == n)
//         		j = 0;
//         	while(count--)
//         	{
//         		if(nums[j] > nums[i])
//         		{
//         			ans.push_back(nums[j]);
//         			found = true;
//         			break;
//         		}
//         		if(++j == n)
//         			j = 0;
//         	}
//         	if(!found)
//         		ans.push_back(-1);
//         }
//         return ans;
//     }
// };

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size(), i;
        vector<int> ans(n,-1);
        stack<int> stk;
        for(int i = 0; i < 2*n; i++)
        {
        	while(!stk.empty() && nums[i%n]> nums[stk.top()])
        	{
        		ans[stk.top()] = nums[i%n];
        		stk.pop();
        	}
        	if(i < n)
        		stk.push(i);
        }
        return ans;
    }
};