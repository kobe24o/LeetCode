class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
    	unordered_map<string, unordered_set<string>> m;
    	//文件内容, 文件路径集合
    	string content, path, file;
    	for(auto& p : paths) 
    	{
    		content = path = file = "";
    		int i = p.find(' ');
    		path = p.substr(0,i)+"/";
    		bool foundcontent = false;
    		for(i++; i < p.size(); ++i)
    		{
    			if(p[i] == '(')
    			{
    				foundcontent = true;
    				continue;
    			}
    			if(p[i] == ')')
    			{
    				m[content].insert(path+file);
    				foundcontent = false;
    				content = file = "";
    				i++;
    				continue;
    			}
    			if(!foundcontent)
    				file += p[i];
    			else
    				content += p[i];
    		}
    	}
    	vector<vector<string>> ans;
    	for(auto& mi : m)
    	{
    		if(mi.second.size() >= 2)
    			ans.push_back(vector<string>(mi.second.begin(), mi.second.end()));
    	}
    	return ans;
    }
};