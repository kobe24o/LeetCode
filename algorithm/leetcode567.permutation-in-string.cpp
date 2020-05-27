class Solution {
public:
    bool checkInclusion(string s1, string s2) {
    	if(s1.size() > s2.size()) return false;
    	int i, j, ct1[26] = {0}, ct2[26] = {0};
    	int n1 = s1.size(), n2 = s2.size();
    	for(i = 0; i < n1; ++i)
    		ct1[s1[i]-'a']++;
    	for(j = 0; j < n1-1; ++j)
    		ct2[s2[j]-'a']++;
    	for(i = 0; j < n2; ++i,++j)
    	{
    		ct2[s2[j]-'a']++;
    		if(eq(ct1, ct2))
    			return true;
    		ct2[s2[i]-'a']--;
    	}
    	return false;
    }
    bool eq(int* ct1, int* ct2)
    {
    	for(int i = 0; i < 26; ++i)
    		if(ct1[i] != ct2[i])
    			return false;
		return true;
    }
};