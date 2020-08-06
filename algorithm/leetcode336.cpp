class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
    	unordered_map<string, int> w_id;
    	set<int> wdLen;
    	for(int i = 0; i < words.size(); ++i)
    	{
    		w_id[words[i]] = i;//字符串idx
    		wdLen.insert(words[i].size());//字符串长度
    	}
    	vector<vector<int>> ans;
    	string front, back, revword;
    	for(int i = 0; i < words.size(); ++i)
    	{
    		revword = words[i];//逆序的字符串
    		reverse(revword.begin(),revword.end());
    		if(w_id.count(revword) && w_id[revword] != i)
    			ans.push_back({i, w_id[revword]});//字符串的逆序存在
    		//遍历words[i]可能的子串长度,寻找前部分存在或者后部分存在
    		//且自身剩余的子串为回文
    		int len = words[i].size();
    		for(auto it = wdLen.begin(); *it < len; ++it)
    		{
    			front = words[i].substr(0, *it);
    			reverse(front.begin(),front.end());
    			back = words[i].substr(*it);
    			if(w_id.count(front) && ispalind(back))//前缀的逆存在
    				ans.push_back({i, w_id[front]});
    		}
    		for(auto it = wdLen.begin(); *it < len; ++it)
    		{
    			front = revword.substr(0, *it);
    			back = revword.substr(*it);
    			if(w_id.count(front) && ispalind(back))//后缀的逆存在
    				ans.push_back({w_id[front], i});
    		}
    	}
        return ans;
    }
    bool ispalind(string& s)
    {
    	int l = 0, r = s.size()-1;
    	while(l < r)
    		if(s[l++] != s[r--])
    			return false;
		return true;
    }
};