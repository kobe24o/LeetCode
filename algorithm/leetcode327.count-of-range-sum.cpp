class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
    	if(nums.size() == 0)
    		return 0;
    	int i, j, len, n = nums.size(), count=0;
    	vector<vector<int>> dp(n,vector<int>(n,0));//区间[i,j]的和
    	for(i = 0; i < n; ++i)
    	{
    		dp[i][i] = nums[i];
    		if(lower<=dp[i][i] && dp[i][i]<=upper)
    			count++;
    	}
    	for(len = 1; len < n; ++len)
    	{
    		for(i = 0; i < n-len; ++i)
    		{
    			dp[i][i+len] = dp[i][i+len-1] + dp[i+len][i+len];
    			if(lower<=dp[i][i+len] && dp[i][i+len]<=upper)
    				count++;
    		}
    	}
    	return count;
    }
};

class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
    	if(nums.size() == 0)
    		return 0;
    	multiset<long> s;
        s.insert(0);
    	int count = 0;
    	long sum = 0;
    	for(int i = 0; i < nums.size(); ++i)
    	{
    		sum += nums[i];
    		count += distance(s.lower_bound(sum-upper), s.upper_bound(sum-lower));
            s.insert(sum);
    	}
    	return count;
    }
};

class Solution {
    vector<long> temp;
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        if(nums.size() == 0)
            return 0;
        vector<long> sum(nums.size()+1, 0);
        temp.resize(nums.size()+1);
        for(int i = 1; i < sum.size(); ++i)
            sum[i] = sum[i-1] + nums[i-1];
        return mergeSort(sum,0,sum.size()-1,lower,upper);
    }

    int mergeSort(vector<long>& sum, int l, int r, int lower, int upper)
    {
        if(l >= r)
            return 0;
        int mid = l+((r-l)>>1), count = 0;
        count += mergeSort(sum, l, mid, lower, upper);
        count += mergeSort(sum, mid+1, r, lower, upper);
        int i = l, jlo = mid+1, jup = mid+1;
        while(i <= mid)
        {
            while(jlo <= r && sum[jlo]-sum[i] < lower)
                jlo++;
            while(jup <= r && sum[jup]-sum[i] <= upper)
                jup++;
            count += jup-jlo;
            i++;
        }
        i = l; int j = mid+1, k = 0;
        while(i <= mid && j <= r)
        {
            if(sum[i] <= sum[j])
                temp[k++] = sum[i++];
            else
                temp[k++] = sum[j++];
        }
        if(i <= mid)
            while(i <= mid)
                temp[k++] = sum[i++];
        else
            while(j <= r)
                temp[k++] = sum[j++];
        for(i = 0, j = l; i < k; ++i)
            sum[l++] = temp[i];
        return count;
    }
};