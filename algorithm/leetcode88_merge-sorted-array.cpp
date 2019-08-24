class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int n1 = nums1.size();
        int idx1 = 0, idx2 = 0;
        while(idx1 < m && idx2 < n)
        {
            if(nums1[idx1] < nums2[idx2])
                nums1.push_back(nums1[idx1++]);
            else
                nums1.push_back(nums2[idx2++]);
        }
        if(idx1 == m)
        {
            while(idx2 < n)
                nums1.push_back(nums2[idx2++]);
        }
        else//(idx2 == n)
        {
            while(idx1 < m)
                nums1.push_back(nums1[idx1++]);
        }
        nums1.erase(nums1.begin(),nums1.begin()+n1);
    }
};