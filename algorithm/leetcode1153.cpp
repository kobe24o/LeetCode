class Solution {
public:
    bool canConvert(string str1, string str2) {
    	if(str1 == str2) return true;
    	unordered_map<char, char> m1_2;
    	int count = 0;
    	vector<bool> alp(26, false);
    	for(int i = 0; i < str2.length(); ++i)
    	{
    		if(!alp[str2[i]-'a'])
    		{
    			alp[str2[i]-'a'] = true;
    			count++;
    		}
    	}
    	if(count == 26) return false;
    	//两字符串不相等，且后者有26种字符肯定有冲突
    	// "aacdefghijklmnopqrstuvwxyz"
		// "abcdefghijklmnopqrstuvwxyz"
		
		for(int i = 0; i < str1.length(); ++i)
		{
			if(!m1_2.count(str1[i]))
				m1_2[str1[i]] = str2[i];
			else if(m1_2[str1[i]] != str2[i])
				return false;
		}
    	return true;
    }
};