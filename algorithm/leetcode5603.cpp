class Solution {
public:
    bool closeStrings(string word1, string word2) {
    	if(word1.size() != word2.size())
    		return false;
    	vector<int> ct1(26,0), ct2(26,0);
    	for(auto c : word1)
    		ct1[c-'a']++;
    	for(auto c : word2)
    		ct2[c-'a']++;
    	sort(ct1.begin(), ct1.end());
    	sort(ct2.begin(), ct2.end());
    	return ct1 == ct2;
    }
};