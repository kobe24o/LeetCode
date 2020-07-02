class Solution {
public:
    bool isMajorityElement(vector<int>& nums, int target) {
    	int count = 0, n = nums.size();
    	for(int i = 0; i < n; ++i)
    		if(nums[i] == target)
    			count++;
        if(n&1)
		    return count > n/2;
        return count >= n/2+1;
    }
};

class Solution {
public:
    bool isMajorityElement(vector<int>& nums, int target) {
        int i = bs1(nums,0,nums.size()-1, target);
        int j = bs2(nums,0,nums.size()-1, target);
        int count = (i!=-1&&j!=-1) ? (j-i+1) : 0;
        int n = nums.size();
        if(n&1)
		    return count > n/2;
        return count >= n/2+1;
    }
    int bs1(vector<int>& a, int l, int r, int t)
    {   //最前面的目标
        int mid;
        while(l <= r)
        {
            mid = l+((r-l)>>1);
            if(a[mid] < t)
                l = mid+1;
            else if(a[mid] > t)
                r = mid-1;
            else
            {
                if(mid==0 || a[mid-1] < t)
                    return mid;
                r = mid - 1;
            }
        }
        return -1;
    }
    int bs2(vector<int>& a, int l, int r, int t)
    {   //最后面的目标
        int mid;
        while(l <= r)
        {
            mid = l+((r-l)>>1);
            if(a[mid] < t)
                l = mid+1;
            else if(a[mid] > t)
                r = mid-1;
            else
            {
                if(mid==a.size()-1 || a[mid+1] > t)
                    return mid;
                l = mid + 1;
            }
        }
        return -1;
    }
};