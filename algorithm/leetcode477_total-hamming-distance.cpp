class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int n1, n0;//1,0的个数
        int i, j, t, dis = 0;
        for(i = 0; i < 32; ++i)
        {
        	n1 = n0 = 0;
        	for(j = 0; j < nums.size(); ++j)
        	{
        		t = nums[j] & (1<<i);
        		if(t)
        			n1++;
        		else
        			n0++;
        	}
        	dis += n1*n0;
        }
        return dis;
    }
};