class Solution {
public:
    vector<int> peopleIndexes(vector<vector<string>>& favoriteCompanies) {
    	map<int,set<vector<string>>> m;//len,排序后的字符
    	for(auto& fc : favoriteCompanies)
    	{
    		sort(fc.begin(), fc.end());
    		m[int(fc.size())].insert(fc);
    	}
    	vector<int> ans;
    	int len;
    	bool flag;
    	for(int i = 0; i < favoriteCompanies.size(); ++i)
    	{
    		len = favoriteCompanies[i].size();
    		//单词个数，只需要在大于它的集合里查找
    		auto it = m.lower_bound(len+1);
    		flag = true;
    		for(auto iter = it; iter != m.end(); ++iter)
    		{

    			for(auto sit = iter->second.begin(); sit != iter->second.end(); ++sit)
    			{
    				if(includes(sit->begin(),sit->end(),favoriteCompanies[i].begin(),favoriteCompanies[i].end()))
    				{
    					flag = false;
    					break;
    				}
    			}
    			if(!flag)
    				break;
    		}
    		if(flag)
    			ans.push_back(i);
    	}
    	return ans;
    }
};