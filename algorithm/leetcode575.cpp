class Solution {
public:
    int distributeCandies(vector<int>& candies) {
        unordered_set<int> s;
        for(auto it = candies.begin(); it != candies.end(); ++it)
        {
        	s.insert(*it);
        }
        if(s.size() >= candies.size()/2)
        	return candies.size()/2;
        else
        	return s.size();
    }
};