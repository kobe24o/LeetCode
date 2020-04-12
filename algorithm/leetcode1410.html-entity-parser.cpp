class Solution {
public:
    string entityParser(string text) {
    	unordered_map<string,string> m = {{"&quot;","\""},{"&apos;","'"},{"&amp;","&"},
    		{"&gt;",">"},{"&lt;","<"},{"&frasl;","/"}};
    	string word;
    	string ans;
    	for(int i = 0; i < text.size(); ++i)
    	{
    		if(text[i] != '&')
    		{
    			ans += text[i];
    		}
    		else
    		{
    			word = "";
    			while(i < text.size())
    			{
    				word += text[i];
    				if(text[i]==';')
    					break;
    				i++;
    			}
    			if(m.count(word))
    				ans += m[word];
    			else
    				ans += word;
    		}
    	}
    	return ans;
    }
};