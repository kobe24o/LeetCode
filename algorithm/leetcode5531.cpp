class Solution {
public:
    int specialArray(vector<int>& nums) {
        int x = 0, ans = -1;
        for(; x <= 1000; x++)
        {
            int count = 0;
            for(int i = 0; i < nums.size(); i++)
            {   
                if(nums[i] >= x)
                {
                    count++;
                }
                if(count > x)
                    break;
            }
            if(count == x)
                ans = x;
        }
        return ans;
    }
};

class Solution {
public:
    int specialArray(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for(int i = 0; i <= nums.size(); ++i)
        {
            int x = nums.end()-lower_bound(nums.begin(), nums.end(), i);
            if(x == i)
                return x;
        }
        return -1;
    }
};

class Solution {
public:
    int specialArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> count(n+1, 0);
        for(auto num : nums) 
            count[min(num, n)]++;
        for(int i = n-1; i >= 0; --i)
            count[i] += count[i+1];//个数后缀和
        for(int i = 0; i <= n; ++i)
            if(count[i] == i)
                return i;
        return -1;
    }
};