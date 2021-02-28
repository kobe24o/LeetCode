class Solution {
public:
    int minOperations(vector<int>& nums1, vector<int>& nums2) {
        int len1 = nums1.size(), len2 = nums2.size();
        if(len1 > 6*len2 || len2 > 6*len1) return -1;
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        int s1 = accumulate(nums1.begin(), nums1.end(),0);
        int s2 = accumulate(nums2.begin(), nums2.end(),0);
        if(s1 > s2)
        {
            swap(nums1, nums2);
            swap(s1, s2);
            swap(len1, len2);
        }
        // 令 s1 <= s2
        int ans = 0, i = 0, j = len2-1;
        int delta1, delta2;
        while(s1 < s2 && (i < len1 || j >= 0))
        {
            delta1 = i < len1 ? 6-nums1[i] : 0;
            delta2 = j >= 0 ? nums2[j]-1 : 0;
            if(i < len1 && delta1 >= delta2)
            {
                s1 += delta1;
                i++;
                ans++;
            }
            else if(j >= 0 && delta2 >= delta1)
            {
                s2 -= delta2;
                j--;
                ans++;
            }
        }
        return ans;
    }
};