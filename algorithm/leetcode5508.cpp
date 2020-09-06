class Solution {
	int s;
public:
    int numTriplets(vector<int>& nums1, vector<int>& nums2) {
    	s = 0;
    	process(nums1, nums2);
    	process(nums2, nums1);
    	return s;
    }
    void process(vector<int>& nums1, vector<int>& nums2) 
    {
    	long long n1 = nums1.size(), n2 = nums2.size(), t1, t2, i, j, k;
    	sort(nums2.begin(), nums2.end());
    	for(i = 0; i < n1; i++)
    	{
    		j = 0, k = n2-1;
    		t1 = (long long)nums1[i]*nums1[i];
    		while(j < k)
    		{
    			t2 = (long long)nums2[j]*nums2[k];
    			if(t1 > t2)
    				j++;
    			else if(t1 < t2)
    				k--;
    			else
    			{
    				if(nums2[j] == nums2[k])
    				{
    					s += (k-j+1)*(k-j)/2;
    					break;
    				}
    				else
    				{
    					int l = nums2[j], r = nums2[k];
    					int ct1 = 0, ct2 = 0;
    					while(nums2[j] == l)
    					{
    						ct1++, j++;
    					}
    					while(nums2[k] == r)
    					{
    						ct2++, k--;
    					}
    					s += ct1*ct2;
    				}
    			}
    		}
    	}
    }
};