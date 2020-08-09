class Solution {
public:
    int longestAwesome(string s) {
    	if(s.size() <= 1) return s.size();
    	unordered_map<int, int> m;
    	m[0] = -1;//空字符所有的0-9位都是0
    	int maxlen = 1, state = 0;
    	for(int i = 0; i < s.size(); ++i)
    	{
    		state ^= (1<<(s[i]-'0'));//该数位奇偶变化了
    		if(m.count(state))//相同的状态，同奇同偶，相减还是偶数个
    			maxlen = max(maxlen, i-m[state]);
    		else
    			m[state] = i;

    		//考虑有一个位不一样，就是相减后只有一个位是奇数，还是回文
    		for(int j = 0; j < 10; ++j)
    		{
    			int odd_state = state^(1<<j);
    			if(m.count(odd_state))
    				maxlen = max(maxlen, i-m[odd_state]);
    		}
    	}
    	return maxlen;
    }
};