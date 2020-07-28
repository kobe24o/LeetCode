class Solution {
public:
    string findSmallestRegion(vector<vector<string>>& regions, string region1, string region2) {
    	unordered_map<string,string> father;
    	for(auto& r : regions)
    		for(int i = 1; i < r.size(); ++i)
    			father[r[i]] = r[0];
    	unordered_set<string> f1;
    	while(region1 != "")
    	{
    		f1.insert(region1);
    		region1 = father[region1];
    	}
    	while(!f1.count(region2))
    		region2 = father[region2];
    	return region2;
    }
};