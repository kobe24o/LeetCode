class Solution {
public:
    vector<int> findSwapValues(vector<int>& array1, vector<int>& array2) {
    	int s1 = 0, s2 = 0, i;
    	unordered_set<int> set;
    	for(i = 0; i < array1.size(); ++i)
    		s1 += array1[i];
    	for(i = 0; i < array2.size(); ++i)
    	{
    		s2 += array2[i];
    		set.insert(array2[i]);
    	}
    	if(abs(s1-s2)%2)
    		return {};
    	int t = (s1-s2)>>1;
    	for(i = 0; i < array1.size(); ++i)
    	{
    		if(set.count(array1[i]-t))
    			return {array1[i], array1[i]-t};
    	}
    	return {};
    }
};