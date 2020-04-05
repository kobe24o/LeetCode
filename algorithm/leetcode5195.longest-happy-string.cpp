class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        vector<pair<int,char>> v;
        v.push_back({a,'a'});
        v.push_back({b,'b'});
        v.push_back({c,'c'});
        string ans;
        int len, i;
        while(true)
        {
        	len = ans.size();
        	sort(v.rbegin(), v.rend());
        	for(i = 0; i < v.size(); ++i)
        	{
        		if(ans.empty() || ans.back() != v[i].second)
        		{
        			if(v[i].first >= 2)
        			{
        				ans += v[i].second+v[i].second;
        				v[i].first -= 2;
        				break;
        			}
        			else if(v[i].first >= 1)
        			{
        				ans += v[i].second;
        				v[i].first -= 1;
        				break;
        			}
        		}
	        }
	        if(ans.size() == len)
	        	break;
        }
        return ans;
    }
};