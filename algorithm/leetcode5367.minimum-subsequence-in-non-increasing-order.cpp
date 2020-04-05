class Solution {
public:
    vector<int> minSubsequence(vector<int>& nums) {
        sort(nums.rbegin(), nums.rend());
        int i, sum = 0, s = 0;
        for(i = 0; i < nums.size(); ++i)
        	sum += nums[i];
        for(i = 0; i < nums.size(); ++i)
        {
        	if(nums[i] + s > sum - nums[i])
        		break;
        	else
        	{
        		s += nums[i];
        		sum -= nums[i];
        	}
        }
        return vector<int>(nums.begin(),nums.begin()+i+1);
    }
};

class Solution {
public:
    vector<int> minSubsequence(vector<int>& nums) {
        int count[101] = {0};
        int i, sum = 0, s = 0;
        for(i = 0; i < nums.size(); ++i)
        {
            sum += nums[i];
            count[nums[i]]++;
        }
        vector<int> ans;
        for(i = 100; i >= 0; --i)
        {
            while(count[i]--)
            {
                if(s+i > sum-i)
                {
                    ans.push_back(i);
                    return ans;
                }
                else
                {
                    s += i;
                    sum -= i;
                    ans.push_back(i);
                }
            }
        }
        return ans;
    }
};