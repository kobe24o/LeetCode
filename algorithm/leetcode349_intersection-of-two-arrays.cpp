class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.empty() || nums2.empty())
        	return {};
        unordered_set<int> set1;
        vector<int> ans;
        for(auto it = nums1.begin(); it != nums1.end(); ++it)
        {
        	if(set1.find(*it) == set1.end())
        		set1.insert(*it);
        }
        for(auto it = nums2.begin(); it != nums2.end(); ++it)
        {
        	auto iter = set1.find(*it);
        	if(iter != set1.end())
        	{
        		ans.push_back(*it);
        		set1.erase(iter);
        	}
        }
        return ans;  
    }
};