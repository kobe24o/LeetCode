class Solution {
public:
    int maxNonOverlapping(vector<int>& nums, int target) {
        unordered_set<int> set;
        set.insert(0);//和为0存在
        int sum = 0, count = 0;
        for(int i = 0; i < nums.size(); ++i)
        {
            sum += nums[i];
            if(set.count(sum-target))
            {
                count++;
                set.clear();
            }
            set.insert(sum);
        }
        return count;
    }
};