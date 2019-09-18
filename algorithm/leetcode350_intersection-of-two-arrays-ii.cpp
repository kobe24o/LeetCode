class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> m1;
        int i;
        vector<int> ans;
        for(i = 0; i < nums1.size(); ++i)
        {
            if(m1.find(nums1[i]) == m1.end())
                m1[nums1[i]] = 1;
            else
                m1[nums1[i]]++;
        }
        for(i = 0; i < nums2.size(); ++i)
        {
            if(m1.find(nums2[i]) != m1.end() && m1[nums2[i]] > 0)
            {
                ans.push_back(nums2[i]);
                m1[nums2[i]]--;
            }
        }
        return ans;
    }
};

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        int i, j;
        vector<int> ans;
        for(i = 0, j = 0; i < nums1.size() && j < nums2.size(); )
        {
            if(nums1[i] < nums2[j])
            	++i;
            else if(nums1[i] > nums2[j])
            	++j;
            else// nums1[i] == nums2[j]
            {
            	ans.push_back(nums1[i]);
            	++i,++j;
            }
        }
        return ans;
    }
};