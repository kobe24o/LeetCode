class Solution {
public:
    int numJewelsInStones(string J, string S) {
        unordered_set<char> s;
        int i, count = 0;
        for(i = 0; i < J.size(); ++i)
        {
        	s.insert(J[i]);
        }
        for(i = 0; i < S.size(); ++i)
        {
        	if(s.find(S[i]) != s.end())
        		++count;
        }
        return count;
    }
};