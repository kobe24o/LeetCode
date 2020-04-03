class Solution {
public:
    vector<string> trulyMostPopular(vector<string>& names, vector<string>& synonyms) {
    	string name, name1;
    	int i, count;
    	unordered_map<string,string> tran;
    	unordered_map<string,int> m;
    	for(auto& n : synonyms)
    	{
    		i = n.find(",");
    		name = n.substr(1,i-1);
    		name1 = n.substr(i+1,n.size()-i-2);
    		if(name < name1)
    			swap(name, name1);
    		tran[name] = name1;
    	}
    	for(string& n : names)
    	{
    		i = n.find("(");
    		name = n.substr(0,i);
    		count = 0;
    		while(++i < n.size()-1)
    		{
    			count = 10*count+n[i]-'0';
    		}
    		m[name] = count;
    	}
    	for(auto& mi : m)
    	{
    		name = mi.first;
    		count = 0;
    		while(tran.count(name))
    		{
    			count += m[name];
    			m[name] = 0;
    			name = tran[name];
    		}
    		m[name] += count;
    	}
    	vector<string> ans;
    	for(auto& mi : m)
    	{
    		if(mi.second)
    			ans.push_back(mi.first+"("+to_string(mi.second)+")");
    	}
    	return ans;
    }
};