class Solution {
public:
    int maxSum(vector<int>& nums1, vector<int>& nums2) {
    	long long ans = 0, up_sum = 0, down_sum = 0, up_num, down_num;
    	int i = 0, j = 0, n1 = nums1.size(), n2 = nums2.size();
    	while(i < n1 && j < n2)
    	{
    		if(nums1[i] < nums2[j])
	    	{
	    		up_sum += nums1[i++];
	    	}
	    	else if(nums1[i] > nums2[j])
	    	{
	    		down_sum += nums2[j++];
	    	}
	    	else if(nums1[i] == nums2[j])
	    	{
	    		up_sum += nums1[i++];
	    		down_sum += nums2[j++];
	    		ans = (ans+max(up_sum, down_sum))%1000000007;
	    		up_sum = down_sum = 0;
	    	}
    	}
    	while(i < n1)
    		up_sum += nums1[i++];
    	while(j < n2)
    		down_sum += nums2[j++];
    	ans = (ans+max(up_sum, down_sum))%1000000007;
    	return ans;
    }
};