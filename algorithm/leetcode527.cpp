class Solution {
    vector<string> ans;
    unordered_map<string,int> m;
public:
    vector<string> wordsAbbreviation(vector<string>& dict) {
    	int i, j, k, n = dict.size();
    	for(i = 0; i < n; ++i)
    		m[dict[i]] = i;
    	sort(dict.begin(), dict.end(),[&](auto a, auto b){
    		if(a.front() == b.front())
    			return a.back() < b.back();
    		return a.front() < b.front();
    	});
    	ans.resize(n);
    	string temp;
    	for(i = 0, j = 0; i < n; ++i)
    	{
    		if(dict[i].size()<=3)
    		{
    			ans[m[dict[i]]] = dict[i];
    			continue;
    		}
    		j = i+1;
    		if(j==n || (j < n && ((dict[i][0]!=dict[j][0]) 
    					|| dict[i].back()!=dict[j].back())))
    		{
    			temp = dict[i].front()+to_string(dict[i].size()-2)+dict[i].back();
    			ans[m[dict[i]]] = temp.size()<dict[i].size() ? temp : dict[i];
    		}
    		else
    		{
    			unordered_map<string,int> map;
    			map[dict[i]] = m[dict[i]];
    			while(j < n && dict[i][0]==dict[j][0] && dict[i].back()==dict[j].back())
    			{
    				map[dict[j]] = m[dict[j]];
    				j++,i++;
    			}
    			k = 0;
    			while(!good(map,k))
    				k++;
    			for(auto it = map.begin(); it != map.end(); ++it)
    			{
    				string str = it->first;
    				temp = str.substr(0,1+k)+to_string(str.size()-k-2)+str.back();
    				ans[it->second] = temp.size()<str.size() ? temp : str;
    			}
    		}
    	}
        return ans;
    }
    bool good(unordered_map<string,int> &map, int k)
    {
    	string str;
    	int id, n, frontn;
    	unordered_set<string> s;
    	for(auto it = map.begin(); it != map.end(); ++it)
    	{
    		id = it->second;
    		str = it->first;
    		n = str.size()-2-k;
    		frontn = 1+k;
            if(n)
    		{
                str = str.substr(0,1+k)+to_string(n)+str.back();
    		    s.insert(str);
            }
            else
            {
                map.erase(str);
                ans[id] = str;
            }
    	}
    	return s.size() == map.size();
    }
};