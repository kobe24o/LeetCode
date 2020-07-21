class Solution {
public:
    vector<int> sortTransformedArray(vector<int>& nums, int a, int b, int c) {
    	int n = nums.size();
    	vector<int> ans(n);
        if(a == 0)
        {
            for(int i = 0; i < n; ++i)
            	ans[i] = f(nums[i],a,b,c);
            if(ans[0] > ans[n-1])
            	reverse(ans.begin(),ans.end());
            return ans;
        }
        double axis = -b/(2.0*a);
        int l = 0, r = 1;
        if(axis <= nums[0]) l = -1, r = 0;
        else if(axis >= nums[n-1]) l = n-1, r = n;
        else
        {
            while(nums[l]<axis)
                l++;
            l--, r = l+1;
        }
        
        double disl, disr;
        int i = 0;
        while(l>=0 || r<n)
        {
            disl = (l>=0)? fabs(nums[l]-axis) : LONG_MAX;
            disr = (r<n)? fabs(nums[r]-axis) : LONG_MAX;
            if(disl < disr)
            {
                ans[i++] = f(nums[l],a,b,c);
                l--;
            } 
            else
            {
                ans[i++] = f(nums[r],a,b,c);
                r++;
            }
        }
        if(ans[0] > ans[n-1])
            reverse(ans.begin(),ans.end());
        return ans;
    }
    int f(int x, int a, int b, int c)
    {
        return a*x*x+b*x+c;
    }
};