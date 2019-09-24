class NumArray {
	int *sum = NULL;
	int n;
public:
    NumArray(vector<int>& nums) {
    	if(nums.empty())
    		return;
    	n = nums.size();
    	sum = new int [n];
    	sum[0] = nums[0];
        for(int i = 1; i < nums.size(); ++i)
        	sum[i] = sum[i-1]+nums[i];
    }
    
    void update(int i, int val) {
    	if(!sum)
    		return;
    	int differ;
    	if(i == 0)
    		differ = val-sum[i];
    	else
    		differ = val-(sum[i]-sum[i-1]);
        for(int k = i; k < n; ++k)
        	sum[k] += differ;
    }
    
    int sumRange(int i, int j) {
    	if(!sum)
    		return 0;
        if(i != 0)
        {
        	return sum[j]-sum[i-1];
        }
        return sum[j];
    }
};