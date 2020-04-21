class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
    	int i, cnt = 0, n = nums.size(), count = 0;
    	vector<int> oddPos(n+2);
    	for(i = 0; i < n; ++i)
    	{
    		if(nums[i] & 1)//奇数
    			oddPos[++cnt] = i;
    	}
    	oddPos[0] = -1, oddPos[++cnt] = n;//边界，假设两边有0个偶数
    	for(i = 1; i+k <= cnt; ++i)
    		count += (oddPos[i]-oddPos[i-1])*(oddPos[i+k]-oddPos[i+k-1]);
	    return count;
    }
};

class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
    	int i, oddcnt = 0, n = nums.size(), count = 0;
    	vector<int> preOddCnt(n+1,0);
    	preOddCnt[0] = 1;//边界，如果全为奇数，
    	for(i = 0; i < n; ++i)
    	{
    		oddcnt += (nums[i]&1);
    		count += oddcnt >= k ? preOddCnt[oddcnt-k] : 0;
    		preOddCnt[oddcnt] += 1;
    	}
	    return count;
    }
};