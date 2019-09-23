class NumArray {
	vector<int> sum;
public:
    NumArray(vector<int>& nums) {
    	int tmp = 0;
        for(int i = 0; i < nums.size(); ++i)
        {
        	tmp += nums[i];
        	sum.push_back(tmp);
        }
    }
    
    int sumRange(int i, int j) {
        if(i != 0)
            return sum[j]-sum[i-1];
        else
            return sum[j];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */