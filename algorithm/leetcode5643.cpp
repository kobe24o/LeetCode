class Solution {
public:
    int waysToSplit(vector<int>& nums) {
        int n = nums.size();
        vector<int> presum(nums);
        for(int i = 1; i < n; i++)
            presum[i] += presum[i-1];//前缀和
        long long ans = 0, mod = 1e9+7;
        for(int i = 0; i < n-2; i++)
        {
            int a = presum[i];
            auto it = lower_bound(presum, i+1, n-2, 2*a);
            //第二段的前缀和至少为 2a, 在 位置 [i+1, n-2] 内查找 
            if(it == -1)
                break;
            // b = presum[it]-a,  c = presum[n-1]-presum[it]
            // c >= b,  presum[it] <= (presum[n-1]+a)/2
            auto it1 = upper_bound(presum, i+1, n-2, (presum[n-1]+a)/2);
            if(it1 != -1 && it1>=it)
                ans = (ans+it1-it+1)%mod;
        }
        return ans;
    }
    int lower_bound(vector<int>& presum, int L, int R, int t)
    {
        int l = L, r = R, n = presum.size(), mid;
        while(l <= r)
        {
            int mid = (l+r)/2;
            if(presum[mid] < t)
                l = mid + 1;
            else
            {
                if(mid==L || (presum[mid-1] < t))
                    return mid;
                else
                    r = mid - 1;
            }
        }
        return -1;
    }
    int upper_bound(vector<int>& presum,  int L, int R, int t)
    {
        int l = L, r = R, n = presum.size(), mid;
        while(l <= r)
        {
            int mid = (l+r)/2;
            if(presum[mid] > t)
                r = mid - 1;
            else
            {
                if(mid==R || (presum[mid+1] > t))
                    return mid;
                else
                    l = mid + 1;
            }
        }
        return -1;
    }
};
