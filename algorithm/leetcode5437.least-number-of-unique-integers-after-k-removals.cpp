class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
    	unordered_map<int,int> m;
    	int i;
    	for(i = 0; i < arr.size(); ++i)
    		m[arr[i]]++;
    	vector<int> count(m.size());
    	i = 0;
    	for(auto it = m.begin(); it != m.end(); ++it)
    		count[i++] = it->second;
    	sort(count.begin(), count.end());
    	i = 0;
    	while(k > 0)
    	{
    		k -= count[i];
    		if(k >= 0)
    			i++;
    	}
    	return count.size()-i;
    }
};