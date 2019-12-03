class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
    	int ans = 0;
        for(int i = 0; i < nums.size(); ++i)
        	ans ^= nums[i];
        return ans;
    }
};

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
    	int i=0, j=nums.size()-1, mid;
    	while(i <= j)
    	{
    		mid = i+((j-i)>>1);
    	}
        
    }
};