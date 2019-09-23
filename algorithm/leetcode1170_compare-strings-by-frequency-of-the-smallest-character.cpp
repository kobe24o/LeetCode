class Solution {
public:
    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
        int count[26], i, j, k = 0;
        vector<int> qc(queries.size()), wc(words.size()), ans(queries.size());
        for (i = 0; i < queries.size(); ++i)
        {
        	memset(count, 0, 26*sizeof(int));
        	for(j = 0; j < queries[i].size(); ++j)
        	{
        		count[queries[i][j]-'a']++;
        	}
        	for(j = 0; j < 26; ++j)
        	{
        		if(count[j] != 0)
        		{
        			qc[k++] = count[j];
        			break;
        		}
        	}
        }
        k = 0;
        for (i = 0; i < words.size(); ++i)
        {
        	memset(count, 0, 26*sizeof(int));
        	for(j = 0; j < words[i].size(); ++j)
        	{
        		count[words[i][j]-'a']++;
        	}
        	for(j = 0; j < 26; ++j)
        	{
        		if(count[j] != 0)
        		{
        			wc[k++] = count[j];
        			break;
        		}
        	}
        }
        for (i = 0; i < qc.size(); ++i)
        {
        	k = 0;
        	for(j = 0; j < wc.size(); ++j)
        	{
        		if(qc[i] < wc[j])
        			++k;
        	}
        	ans[i] = k;
        }
        return ans;
    }
};