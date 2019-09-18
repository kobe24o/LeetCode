class Solution {
public:
    vector<string> commonChars(vector<string>& A) {
    	if(A.empty())
    		return {};
        int ans[26] = {0}, temp[26];
        int i, j;
        char ch;
        for(j = 0; j < A[0].size(); ++j) 
        {
        	ans[A[0][j]-'a']++;
        }
        for(i = 1; i < A.size(); ++i)
        {
        	memset(temp,0,26*sizeof(int));
        	for(j = 0; j < A[i].size(); ++j)
        	{
        		temp[A[i][j]-'a']++;
        	}
        	for(j = 0; j < 26; ++j)
        	{
        		ans[j] = min(ans[j],temp[j]);
        	}
        }
        vector<string> result;
        for(j = 0; j < 26; ++j)
        {
        	i = ans[j];
            ch = 'a'+j;
        	while(i--) 
                result.push_back(string(1,ch));
        }
        return result;
    }
};