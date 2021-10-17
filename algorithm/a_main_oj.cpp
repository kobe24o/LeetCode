#include <bits/stdc++.h>
#include<vector>
#include<string>
#include<iostream>
using namespace std;


class Solution {
    vector<int> neg, zero, pos;
public:
    long long kthSmallestProduct(vector<int>& nums1, vector<int>& nums2, long long k) {
        long long l = -1e10, r = 1e10, mid, ans, p1 = 0, p2 = 0;
        for(int i = 0; i < nums2.size(); ++i)
        {
            if(nums2[i] < 0)
                neg.push_back(nums2[i]);
            else if(nums2[i] > 0)
            {
                pos.push_back(nums2[i]);
            }
            else
                zero.push_back(nums2[i]);
        }
        while(l <= r)
        {
            mid = l+((r-l)>>1);
            long long ct = check(nums1, nums2, mid);
            if(ct >= k)
            {
                ans = mid;
                r = mid-1;
            }
            else
                l = mid+1;
        }
        return ans;
    }
    long long check(vector<int>& nums1, vector<int>& nums2, long long num)
    {
        long long ct = 0; // 计算有多少数是小于等于 num 的
        for(auto a : nums1)
        {
            if(a == 0)
            {
                if(num >= 0)
                    ct += nums2.size();
            }
            else if(a > 0)
            {
                if(num == 0)
                    ct += neg.size()+zero.size();
                else if(num > 0)
                {
                    auto x = upper_bound(pos.begin(), pos.end(), num/a);
                    ct += x-pos.begin()+neg.size()+zero.size();
                }
                else
                {
                    auto x = upper_bound(neg.begin(), neg.end(), floor(num/a));
                    ct += x-neg.begin();
                }
            }
            else // a < 0
            {
                if(num == 0)
                    ct += pos.size()+zero.size();
                else if(num > 0)
                {
                    auto x = lower_bound(neg.begin(), neg.end(), floor(num/a));
                    ct += neg.end()-x+pos.size()+zero.size();
                }
                else
                {
                    auto x = lower_bound(pos.begin(), pos.end(), num/a+1);
                    ct += pos.end()-x;
                }
            }
        }
        return ct;
    }
};

int main()
{

    Solution s;
    vector<int> nums1 = {-2,-1,0,1,2}, nums2 = {-3,-1,2,4,5};
    cout << s.kthSmallestProduct(nums1, nums2, 3) << endl;
    cout << floor(-5/2);
    cout << ceil(-5/2);
    return 0;
}