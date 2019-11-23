class Solution {
public:
    string customSortString(string S, string T) {
        map<int,char> m;//S中的字符的出现次序--对应字符
        int i;
        for(i = 0; i < S.size(); ++i)
        	m[i] = S[i];
        int count[26] = {0};
        for(i = 0; i < T.size(); ++i)
        	count[T[i]-'a']++;//字符个数计数
        string ans;
        for(auto& mi : m)//默认按key升序
        {
        	ans += string(count[mi.second-'a'], mi.second);
        	count[mi.second-'a'] = 0;
        }
        for(i = 0; i < 26; ++i)
        	if(count[i] != 0)//剩余不在S中的字符
        		ans += string(count[i], 'a'+i);
        return ans;
    }
};