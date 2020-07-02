class Solution {
public:
    string removeVowels(string S) {
    	unordered_set<char> s = {'a','e','i','o','u'};
    	string ans;
    	for(char ch : S)
    		if(!s.count(ch))
    			ans += ch;
		return ans;
    }
};