class Solution {
public:
    int fixedPoint(vector<int>& A) {
    	for(int i = 0; i < A.size(); ++i)
    	{
    		if(A[i] == i)
    			return i;
    	}
    	return -1;
    }
};

class Solution {
public:
    int fixedPoint(vector<int>& A) {
        int l = 0, r = A.size() -1, mid, ans = INT_MAX;
        while(l <= r) 
        {
            mid = (l + r)>>1;
            if(mid < A[mid])
            	r = mid-1;
            else if(mid > A[mid])
                l = mid+1;
            else
            {
            	ans = min(ans,mid);
            	r = mid-1;
            }
        }
        return ans==INT_MAX ? -1 : ans;
    }
};