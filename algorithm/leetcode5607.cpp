class Solution {
public:
    int waysToMakeFair(vector<int>& nums) {
        int n = nums.size();
        int i = 0, odd = 0, even = 0;
        vector<int> odd1(n, 0), odd2(n, 0), even1(n, 0), even2(n, 0);
        for(i = 0, odd = 0, even = 0; i < n; i++) 
        {
            if(i%2 == 1)
            {
                odd1[i] = odd;//除了i下标，之前的奇数和
                even1[i] = even;//奇数下标之前的偶数下标之和
                odd += nums[i];
            }
            else
            {
                even1[i] = even;//除了i下标，之前的偶数和
                odd1[i] = odd;
                even += nums[i];
            }
        }
        for(i = n-1, odd = 0, even = 0; i >= 0; i--) 
        {
            if(i%2 == 1)
            {
                odd2[i] = odd;//除了i下标，之后的奇数和
                even2[i] = even;
                odd += nums[i];
            }
            else
            {
                even2[i] = even;//除了i下标，之后的偶数和
                odd2[i] = odd;
                even += nums[i];
            }
        }
        int ans = 0;
        for(int i = 0; i < n; ++i)
        {   //删除 i 了，后序的偶数和变成奇数和
            //奇数和变成偶数和
            if(odd1[i]+even2[i] == even1[i]+odd2[i])
                ans++;
        }
        return ans;
    }
};