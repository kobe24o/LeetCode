class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        map<int,int> m;
        set<int> s;
        for(int i = 0; i < arr1.size(); ++i)
        {
        	if(m.find(arr1[i]) == m.end())
        		m[arr1[i]] = 1;
        	else
        		m[arr1[i]]++;
        }
        for(int i = 0; i < arr2.size(); ++i)
        	s.insert(arr2[i]);
        vector<int> ans;
        int count;
        for(int i = 0; i < arr2.size(); ++i)
        {
        	count = m[arr2[i]];
        	while(count--)
        		ans.push_back(arr2[i]);
        }
        sort(arr1.begin(), arr1.end());
        for(int i = 0; i < arr1.size(); ++i)
        {
        	if(s.find(arr1[i]) == s.end())
        		ans.push_back(arr1[i]);
        }
        return ans;
    }
};