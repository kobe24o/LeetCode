class Solution {
public:
    vector<string> printVertically(string s) {
    	vector<int> idx;
        s.push_back(' ');
    	int i, n = s.size();
    	char prev = ' ';
    	for(i = 0; i < n; ++i)
    	{
    		if(prev==' ' && s[i] != ' ')
    			idx.push_back(i);
    		prev = s[i];
    	}
    	vector<string> ans;
    	string str;
    	while(1)
    	{
    		str = "";
    		for(i = 0; i < idx.size(); ++i)
    		{
    			if(idx[i] != -1)
    			{
    				str += s[idx[i]++];
    				if(s[idx[i]] == ' ')
    					idx[i] = -1;
    			}
    			else
    				str += ' ';
    		}
    		while(!str.empty() && str.back()==' ')
    			str.pop_back();
    		if(str == "")
    			break;
    		else
    			ans.push_back(str);
    	}
    	return ans;
    }
};