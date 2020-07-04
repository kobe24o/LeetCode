class Solution {
public:
    int numKLenSubstrNoRepeats(string S, int K) {
    	int i = 0, j = 0, n = S.size(),count = 0;
    	unordered_set<char> set;
    	for( ; j < n; ++j)
    	{
    		while(set.size() >= K || set.count(S[j]))
    			set.erase(S[i++]);
    		set.insert(S[j]);
    		if(set.size()==K)
    			count++;
    	}
        return count;
    }
};