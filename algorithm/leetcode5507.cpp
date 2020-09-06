class Solution {
public:
    string modifyString(string s) {
    	vector<char> ch(26);
    	for(int i = 0; i < 26; i++)
    		ch[i] = 'a'+i;
    	for(int i = 0; i < s.size(); i++)
    	{
    		if(s[i] == '?')
    		{
    			set<char> st(ch.begin(), ch.end());
    			if(i > 0)
    				st.erase(s[i-1]);
    			if(i+1 < s.size())
    				st.erase(s[i+1]);
    			s[i] = *st.begin();
    		}
    	}
    	return s;
    }
};