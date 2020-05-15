class Solution {
public:
    int findSubstringInWraproundString(string p) {
    	int i, n = 0, count[26] = {0};//以26个字符结尾的连续的最大长度
    	char prev = '*';
    	for(i = 0; i < p.size(); ++i)
    	{
			if((prev-'a'+1)%26 == p[i]-'a')
				n++;
			else
				n = 1;
			count[p[i]-'a'] = max(count[p[i]-'a'], n);
    		prev = p[i];
    	}
    	n = 0;
    	for(i = 0; i < 26; ++i)
    		n += count[i];
    	return n;
    }
};