class Solution {
public:
    string freqAlphabets(string s) {
        string ans;
        for(int i = s.size()-1; i >= 0; --i)
        {
        	if(s[i] != '#')//一位数
        	{
        		ans.insert(0,1,'a'+s[i]-'1');
        	}
        	else
        	{
        		ans.insert(0,1,(s[i-2]-'0')*10+(s[i-1]-'0')-1+'a');
                i -= 2;
        	}
        }
        return ans;
    }
};