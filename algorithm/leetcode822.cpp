class Solution {
public:
    int flipgame(vector<int>& fronts, vector<int>& backs) {
    	int minnum = INT_MAX;
    	unordered_set<int> s;
    	for(int i = 0; i < fronts.size(); ++i)
    	{
    		if(fronts[i] == backs[i])
    			s.insert(fronts[i]);
    	}
    	for(int i = 0; i < fronts.size(); ++i)
    	{
    		if(fronts[i] == backs[i])
    			continue;
    		if(!s.count(fronts[i]))
    			minnum = min(minnum, fronts[i]);
    		if(!s.count(backs[i]))
    			minnum = min(minnum, backs[i]);
    	}
    	return minnum==INT_MAX ? 0 : minnum;
    }
};