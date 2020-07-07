class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
    	int k = 1, i = 0, j = 0, maxlen = 0;
    	for( ; j < nums.size(); ++j)
    	{
    		if(nums[j]==0)
    		{   
                k--;
                while(k < 0)
                {
                    if(nums[i++]==0)
                        k++;
                }
    		}
    		maxlen = max(maxlen,j-i+1);
    	}
        return maxlen;
    }
};