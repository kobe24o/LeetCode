typedef unsigned long long ull;
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        if(words.empty() || words.size()*words[0].size() > s.size()) 
        	return {};
        int i, j, wlen = words[0].size(), n = words.size();
        unordered_map<ull,int> m;
        for(auto& w : words)
        {
        	ull v = 0;
        	for(char ch : w)
        		v = v*128+ch;
        	m[v]++;//字符转成128进制的数，计数
        }
        //字符串s每个位置开始后的wlen个字符的ull表示
        vector<ull> hashv(s.size(),0);
        ull pown = 1;
        for(i = 0; i < wlen; ++i)
        {
        	pown *= 128;
        	hashv[0] = hashv[0]*128+s[i];
        }
        for(i = 1; i <= s.size()-wlen; ++i)
        {
        	hashv[i] = hashv[i-1]*128-s[i-1]*pown+s[i+wlen-1];
        }

        vector<int> ans;
        bool ok;
        for(i = 0; i <= s.size()-n*wlen; ++i)
        {
        	unordered_map<ull, int> temp(m);
        	ok = true;
        	for(j = i; j < n*wlen+i; j+=wlen)
        	{
        		if(--temp[hashv[j]] < 0)
        		{
        			ok = false;
        			break;
        		}
        	}
        	if(ok) ans.push_back(i);
        }
        return ans;
    }
};