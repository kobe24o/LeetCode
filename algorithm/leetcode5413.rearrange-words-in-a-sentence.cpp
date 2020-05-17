class Solution {
public:
    string arrangeWords(string text) {
    	text[0] += 32;//A 65, a 97
        map<int,vector<string>> m;//len,words
        istringstream in(text);
        string word, ans;
        while(in >> word)   
        {
        	m[int(word.size())].push_back(word);
        }
        for(auto& mi : m)
        	for(auto& w : mi.second)
        		ans += w+" ";
    	ans.pop_back();
    	ans[0] -= 32;
    	return ans;
    }
};