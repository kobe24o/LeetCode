class Solution {
public:
    vector<int> partitionLabels(string S) {
        int ans = 0, i, j, right;
        map<char, int> endpos;
        for(i = S.size()-1; i >= 0; --i)
        {
        	if(endpos.find(S[i]) == endpos.end())
        		endpos[S[i]] = i;
        }
        i = 0;
        while(i < S.size())
        {
        	right = endpos[S[i]];
        	for(j = i; j <= right; ++j)
        	{
        		if(endpos[S[j]] > right)
        			right = endpos[S[j]];
        	}
        	++ans;
        	i = j;
        }
        return ans;
    }
};