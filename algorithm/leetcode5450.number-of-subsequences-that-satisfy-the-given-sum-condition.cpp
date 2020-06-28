class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int i = 0, j;
        unsigned long long count = 0;
        for(i = 0; i < nums.size(); ++i)
        {
            // if(nums[i] > target/2+1)
            //     break;
            j = bs(nums,target-nums[i]);
            if(j != -1 && j >= i)
                count = (count+mypow(j-i))%int(1e9+7);
        }
        return count;
    }
    
    int bs(vector<int>& a, int t)
    {
        int i = 0, j = a.size()-1, mid;
        while(i <=j)
        {
            mid = (i+j)/2;
            if(a[mid] > t)
                j = mid-1;
            else
            {
                if(mid==a.size()-1 || a[mid+1] > t)
                    return mid;
                else
                    i = mid+1;
            }
        }
        return -1;
    }
    int mypow(int n)
    {
        long long s = 1, p = 2;
        while(n)
        {
            if(n%2)
                s *= p, s %= int(1e9+7);
            p *= p;
            p %= int(1e9+7);
            n /= 2;
        }
        return s;
    }
};