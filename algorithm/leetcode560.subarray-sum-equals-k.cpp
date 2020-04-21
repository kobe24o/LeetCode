class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> m;//和，数组个数
        int i, sum = 0, count = 0;
        m[0] = 1;//边界
        for(i = 0; i < nums.size(); ++i)
        {
        	sum += nums[i];
        	// m[sum]++;不能写在这
        	count += m[sum-k];
            m[sum]++;
        }
        return count;
    }
};