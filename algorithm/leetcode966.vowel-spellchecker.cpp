class Solution {
public:
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
    	unordered_set<char> vowel = {'a','e','i','o','u'};
    	unordered_set<string> words(wordlist.begin(), wordlist.end());
    	unordered_map<string,string> upper_lower;
    	unordered_map<string,string> vowel_mask;
    	string s1, s2;
    	int i = 0, idx = 0;
    	for(auto& w : wordlist)
    	{
    		words.insert(w);
    		s1 = s2 = w;
    		for(i = 0; i < w.size(); i++)
    		{
    			if(isupper(s1[i]))
    			{
    				s1[i] += 32;//转小写
    				s2[i] += 32;
    			}
    			if(vowel.count(s2[i]))
    				s2[i]='*';
    		}
    		if(!upper_lower.count(s1))
    			upper_lower[s1] = w;
    		if(!vowel_mask.count(s2))
    			vowel_mask[s2] = w;
    	}
    	vector<string> ans(queries.size(),"");
    	for(auto& q : queries)
    	{
    		if(words.count(q))
    			ans[idx] = q;
    		else
    		{
    			s1 = s2 = q;
    			for(i = 0; i < q.size(); i++)
	    		{
	    			if(isupper(s1[i]))
	    			{
	    				s1[i] += 32;//转小写
	    				s2[i] += 32;
	    			}
	    			if(vowel.count(s2[i]))
	    				s2[i]='*';
	    		}
	    		if(upper_lower.count(s1))
	    			ans[idx] = upper_lower[s1];
    			else if(vowel_mask.count(s2))
    				ans[idx] = vowel_mask[s2];
	    	}
	    	idx++;
    	}
    	return ans;
    }
};