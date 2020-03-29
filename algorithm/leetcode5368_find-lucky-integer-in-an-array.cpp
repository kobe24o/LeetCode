class Solution {
public:
    int findLucky(vector<int>& arr) {
    	map<int,int> m;
    	for(int a : arr)
    		m[a]++;
    	int ans = -1;
    	for(auto& mi : m)
    		if(mi.first == mi.second)
    			ans = mi.first;
		return ans;
    }
};