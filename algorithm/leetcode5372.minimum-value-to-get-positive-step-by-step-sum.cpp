class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int val=1, i, sum=0;
        for(i = 0; i < nums.size(); ++i)
        {
            sum += nums[i];
            if(sum >= 1)
                continue;
            else
                val = max(val, 1-sum);
        }
        return val;
    }
};