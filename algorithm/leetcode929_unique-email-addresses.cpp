class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        set<string> s;
        string str;
        int i, j;
        bool meetAt, meetPlus;
        for(i = 0; i < emails.size(); ++i)
        {
        	meetPlus = meetAt = false;
        	str = "";
        	for(j = 0; j < emails[i].size(); ++j)
        	{
        		if(emails[i][j] == '+')
        			meetPlus = true;
        		else if(emails[i][j] == '@')
        		{
        			meetAt = true;
        		}
        		if(!meetAt && !meetPlus && emails[i][j] != '.')
        			str.push_back(emails[i][j]);
        		if(meetAt)
        			str.push_back(emails[i][j]);
        	}
        	s.insert(str);
        }
        return s.size();
    }
};