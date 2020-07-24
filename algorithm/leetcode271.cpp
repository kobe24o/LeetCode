class Codec {
public:

    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string ans;
        for(auto& s : strs)
        	ans += numToHexIntStr(s.size())+s;
        return ans;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string> ans;
        int n;
        string t;
        for(int i = 0; i < s.size(); i += 4+n)
        {
        	n = stoi(s.substr(i,4),0,16);//16进制转成10进制
        	ans.emplace_back(s.substr(i+4,n));
        }
        return ans;
    }

    string numToHexIntStr(int n)
    {
    	char ch[16];
    	sprintf(ch, "%x", n);
    	string ans = ch;
    	while(ans.size() < 4)
    		ans = '0'+ans;
    	return ans;
    }
};