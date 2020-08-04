class Solution {
public:
    vector<string> beforeAndAfterPuzzles(vector<string>& phrases) {
    	unordered_map<string,vector<int>> front;//字符前缀，包含该字符的字符串的idx
    	unordered_map<string,vector<int>> back;//字符后缀，包含该字符的字符串的idx
    	size_t idx1, idx2, len, i, j;
    	for(i=0; i<phrases.size(); ++i)
    	{
    		idx1 = phrases[i].find_first_of(' ');
    		idx2 = phrases[i].find_last_of(' ');
    		if(idx1 != string::npos)
    			front[phrases[i].substr(0,idx1)].push_back(i);
    		else
    			front[phrases[i]].push_back(i);
    		if(idx2 != string::npos)
    			back[phrases[i].substr(idx2+1)].push_back(i);
    		else
    			back[phrases[i]].push_back(i);
    	}
    	set<string> ans;
    	for(auto it1 = back.begin(); it1 != back.end(); ++it1)
    	{
    		if(!front.count(it1->first))
    			continue;
    		len = it1->first.size();
			for(i = 0; i < it1->second.size(); i++)
			{
				idx1 = it1->second[i];
				for(j = 0; j < front[it1->first].size(); j++)
				{
					idx2 = front[it1->first][j];
					if(idx1 == idx2)
						continue;//同一个单词
					ans.insert(phrases[idx1]+phrases[idx2].substr(len));
				}
			}
    	}
    	return vector<string>(ans.begin(), ans.end());
    }
};