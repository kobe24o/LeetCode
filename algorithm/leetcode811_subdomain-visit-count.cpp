class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        int count, i, j;
        vector<string> ans;
        unordered_map<string,int> m;
        string str, temp;
        for(i = 0; i < cpdomains.size(); ++i)
        {
        	str = "";
        	for(j = 0; j < cpdomains[i].size(); ++j)
        	{
        		if(cpdomains[i][j] == ' ')
        		{
        			count = stoi(str);
        			str = "";
        			break;
        		}
        		if(cpdomains[i][j] != ' ')
        			str.push_back(cpdomains[i][j]);
        	}
        	temp = "";
        	for(j = cpdomains[i].size()-1; j >= 0; --j)
        	{
        		if(cpdomains[i][j] != '.' && cpdomains[i][j] != ' ')
        		{
        			str.push_back(cpdomains[i][j]);
        		}
        		else if(cpdomains[i][j] == '.')
        		{
        			reverse(str.begin(), str.end());
        			temp = str+temp;
        			str = ".";
        			if(m.find(temp) == m.end())
        				m[temp] = count;
        			else
        				m[temp] += count;	
        		}
        		else if(cpdomains[i][j] == ' ')
        		{
        			reverse(str.begin(), str.end());
        			temp = str+temp;
        			if(m.find(temp) == m.end())
        				m[temp] = count;
        			else
        				m[temp] += count;
        			break;
        		}
        	}
        }
        for(auto it = m.begin(); it != m.end(); ++it)
        {
        	ans.push_back(to_string(it->second)+' '+it->first);
        }
        return ans;
    }
};