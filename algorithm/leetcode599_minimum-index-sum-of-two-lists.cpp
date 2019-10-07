class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        unordered_map<string,int> r1;
        int min = INT_MAX;
        vector<string> ans;
        for(int i = 0; i < list1.size(); ++i)
        {
        	r1[list1[i]] = i;
        }
        for(int i = 0; i < list2.size(); ++i)
        {
        	if(r1.find(list2[i]) != r1.end())
        	{
        		r1[list2[i]] += i-3000;
        		if(r1[list2[i]] < min)
        			min = r1[list2[i]];
        	}
        }
        for(auto it = r1.begin(); it != r1.end(); ++it)
        	if(it->second == min)
        		ans.push_back(it->first);
    	return ans;
    }
};