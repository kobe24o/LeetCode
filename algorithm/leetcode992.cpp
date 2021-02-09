class Solution {
public:
    int subarraysWithKDistinct(vector<int>& A, int K) {
        int l1 = 0, l2 = 0, r = 0, n = A.size();
        int ct1 = 0, ct2 = 0, ans = 0;
        vector<int> nums1(n+1, 0), nums2(n+1, 0);
        while(r < n)
        {
            if(++nums1[A[r]] == 1)
                ct1++;
            if(++nums2[A[r]] == 1)
                ct2++;
            while(ct1 > K)
            {
                if(--nums1[A[l1]] == 0)
                    ct1--;
                l1++;
            }
            while(ct2 >= K)
            {
                if(--nums2[A[l2]] == 0)
                    ct2--;
                l2++;
            }
            ans += l2-l1;
            r++;
        }
        return ans;
    }
};