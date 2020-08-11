class Solution {//TLE
public:
    double findMaxAverage(vector<int>& nums, int k) {
    	int n = nums.size(), i, j, s;
    	double maxAVG = INT_MIN, avg;
    	vector<int> sum = nums;
    	for(i = 1; i < n; ++i)
    		sum[i] = sum[i-1] + nums[i];
    	for(i = 0; i <= n-k; ++i)
	    	for(j = i+k-1; j < n; ++j)
	    	{
	    		if(i == 0)
	    			s = sum[j];
	    		else
	    			s = sum[j]-sum[i-1];
	    		avg = s/double(j-i+1);
	    		if(avg > maxAVG)
	    			maxAVG = avg;
	    	}
	    return maxAVG;
    }
};

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {

    }
};