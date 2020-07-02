class Solution {
public:
    vector<int> arraysIntersection(vector<int>& arr1, vector<int>& arr2, vector<int>& arr3) {
    	unordered_set<int> s2(arr2.begin(), arr2.end()), s3(arr3.begin(),arr3.end());
    	vector<int> ans;
    	for(int i = 0; i < arr1.size(); ++i)
    	{
    		if(s2.find(arr1[i]) != s2.end() && s3.find(arr1[i])!=s3.end())
    			ans.push_back(arr1[i]);
    	}
    	return ans;
    }
};