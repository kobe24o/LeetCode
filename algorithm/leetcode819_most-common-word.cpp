class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        int i, maxcount = 0;
        string sub;
        unordered_map<string,int> m;
        unordered_set<string> s(banned.begin(), banned.end());
        for(i = 0; i < paragraph.size(); ++i)
        {
        	if(isalpha(paragraph[i]))
        	{
        		sub.push_back(tolower(paragraph[i]));
        		if(i == paragraph.size()-1)
        			m[sub]++;
        	}
        	else
        	{
        		if(sub != "")
        			m[sub]++;
        		sub = "";
        	}
        }
        for(auto rec:m)
        {
        	if(!s.count(rec.first))
        	{
        		if(rec.second > maxcount)
        		{
        			maxcount = rec.second;
        			sub = rec.first;
        		}
        	}
        }
        return sub;
    }
};