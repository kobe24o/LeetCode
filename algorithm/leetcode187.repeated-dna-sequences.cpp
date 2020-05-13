class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
		if(s.size() <= 10)
			return {};
    	unordered_map<string,int> m;
    	int i = 0;
    	while(i < s.size()-9)
    		m[s.substr(i++,10)]++;
    	vector<string> ans;
    	for(auto it = m.begin(); it != m.end(); ++it)
    	{
    		if(it->second > 1)
    			ans.push_back(it->first);
    	}
    	return ans;
    }
};

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
		if(s.size() <= 10)
			return {};
    	map<char,int> m = {{'A',0}, {'G',1}, {'C',2}, {'T',3}};
        unordered_map<int,int> c;
        int num = 0, i = 0, k=10;
        while(i < k-1)
        {
            num <<= 2;
            num |= m[s[i++]];
        }
        vector<string> ans;
        while(i < s.size())
        {
            num = (num<<2)&~(3<<2*k);
            num |= m[s[i]];
            c[num]++;
            if(c[num]==2)
                ans.push_back(s.substr(i-9,10));
            i++;
        }
        return ans;
    }
};