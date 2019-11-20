class Solution {
public:
    string gcdOfStrings(string s1, string s2) {
        while(s1 != s2)
        {
        	if(s1.size() > s2.size())
        		swap(s1,s2);
        	if(s2.find(s1) != 0)
        		return "";
        	s2 = s2.substr(s1.size());
        }
        return s1;
    }
};