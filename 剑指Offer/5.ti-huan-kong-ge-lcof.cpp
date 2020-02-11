class Solution {
public:
    string replaceSpace(string s) {
    	string ans;
        for(auto& ch : s)
        {
        	if(ch == ' ')
        		ans += "%20";
        	else
        		ans += ch;
        }
        return ans;
    }
};

class Solution {
public:
    string replaceSpace(string s) {
        for(int i = 0; i < s.size(); ++i)
        {
        	if(s[i] == ' ')
        	{
        		s.erase(i,1);
        		s.insert(i,"%20");
        		i += 2;
        	}
        }
        return ans;
    }
};