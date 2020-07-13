class Solution {
public:
    int maximumGap(vector<int>& nums) {
    	sort(nums.begin(), nums.end());
    	int n = nums.size(), maxgap = 0;
    	for(int i = 0; i < n-1; ++i)
    	{
    		maxgap = max(maxgap, nums[i+1]-nums[i]);
    	}
    	return maxgap;
    }
};

class Solution {
public:
    int maximumGap(vector<int>& nums) {
    	if(nums.size() <= 1) return 0;
    	int MAX = *max_element(nums.begin(), nums.end());
    	int MIN = *min_element(nums.begin(), nums.end());
    	int n = nums.size(), gap = max(1, (MAX-MIN)/(n-1));
    	int nbuck = (MAX-MIN)/gap+1;
    	vector<vector<int>> buck(nbuck,vector<int>({INT_MAX, INT_MIN}));
    	for(int num : nums)
    	{
    		int id = (num-MIN)/gap;
    		buck[id][0] = min(buck[id][0], num);
    		buck[id][1] = max(buck[id][1], num);
    	}
    	int prev_max = MIN, maxgap = 0;
    	for(int i = 0; i < nbuck; ++i)
    	{
    		if(buck[i][0] == INT_MAX)
    			continue;
    		maxgap = max(maxgap, buck[i][0]-prev_max);
    		prev_max = buck[i][1];
    	}
    	return maxgap;
    }
};