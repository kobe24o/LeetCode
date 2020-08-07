class Solution {
public:
    bool splitArray(vector<int>& nums) {
    	int n = nums.size(), i, j, k;
    	if(n < 7) return false;
    	vector<int> sum(nums);
    	for(i = 1; i < n; i++)
    		sum[i] += sum[i-1];
        int maxnum = *max_element(nums.begin(), nums.end());
        int minnum = *min_element(nums.begin(), nums.end());
    	for(j = 3; j < n-3; j++)
    	{
    		if(abs(sum[n-1]-sum[j]-sum[j-1]) > maxnum-minnum)
    			continue;
    		unordered_set<int> s;
    		for(i = 1; i < j-1; i++)
    		{
    			if(sum[i-1] == sum[j-1]- sum[i])
    				s.insert(sum[i-1]);
    		}
    		for(k = j+2; k < n-1; k++)
    		{
    			if(sum[k-1]-sum[j] == sum[n-1]-sum[k]
    				&& s.count(sum[k-1]-sum[j]))
    				return true;
    		}
    	}
    	return false;
    }
};