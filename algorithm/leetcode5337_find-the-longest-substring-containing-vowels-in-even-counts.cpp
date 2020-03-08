class Solution {
public:
    int findTheLongestSubstring(string s) {
    	unordered_map<int,int> m;	// 前缀异或值，对应的位置
    	int XOR = 0, i, maxlen = 0;
    	m[0] = -1;	//没有元音，位置为-1，方便计算个数
    	for(i = 0; i < s.size(); i++) 
    	{
    		if(s[i]!='a' && s[i]!='e' && s[i]!='i' && s[i]!='o' && s[i]!='u')
    		{
    			if(m.count(XOR))
    				maxlen = max(maxlen, i-m[XOR]);
    		}
    		else//s[i] 是元音
    		{
    			XOR ^= s[i];//元音异或值
    			if(m.count(XOR))
    				maxlen = max(maxlen, i-m[XOR]);
    			else
    				m[XOR] = i;
    		}
    	}
    	return maxlen;
    }
};