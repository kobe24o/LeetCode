class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int i, j;
        unordered_map<int, int> m;
        for(i = 0; i < nums2.size(); ++i)
        {
        	m[nums2[i]] = i;
        }
        vector<int> ans;
        for(i = 0; i < nums1.size(); ++i)
        {
        	for(j = m[nums1[i]]+1; j < nums2.size(); ++j)
        	{
        		if(nums1[i] < nums2[j])
                {
                    ans.push_back(nums2[j]);
                    break;
                }
        		if(j == nums2.size()-1)
                {
                    ans.push_back(-1);
                    break;
                }
        	}
            if(j == nums2.size())
                ans.push_back(-1);
        }
        return ans;
    }
};