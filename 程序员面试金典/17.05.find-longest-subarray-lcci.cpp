class Solution {
public:
    vector<string> findLongestSubarray(vector<string>& array) {
        if(array.size() < 2)
            return {};
        unordered_map<int, vector<int>> m;
        int sum = 0, i;
        for(i = 0; i < array.size(); ++i)
        {
        	if(isdigit(array[i][0]))
        		sum++;
        	else
        		sum--;
        	if(m[sum].size() < 2)
        		m[sum].push_back(i);
        	else
        		m[sum][1] = i;
        }
        if(sum == 0)
        	return array;
        int maxlen = 0;
        vector<int> key;
        for(auto& mi : m)
        {
        	if(mi.second[1]-mi.second[0] > maxlen)
        	{
        		maxlen = mi.second[1]-mi.second[0]
        		key.clear();
        		key.push_back(mi.first);
        	}
        	else if(mi.second[1]-mi.second[0] == maxlen)
        		key.push_back(mi.first);
        }
        int minidx = INT_MAX;
        int ansKey;
        for(int k : key)
        {
        	if(m[k][0] < minidx)
        	{
        		minidx = m[k][0];
        		ansKey = k;
        	}
        }
        return vector<string> (array.begin()+m[ansKey][0], array.begin()+m[ansKey][1]);
    }
};