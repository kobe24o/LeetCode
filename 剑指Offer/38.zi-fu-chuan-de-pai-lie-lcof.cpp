class Solution {
	int n;
	vector<string> ans;
	string str;
public:
    vector<string> permutation(string s) {
        sort(s.begin(), s.end());
        n = s.size(); 
    	vector<bool> visited(n,false);
        bt(s,0,visited);
        return ans;
    }

    void bt(string& s, int count, vector<bool>& visited)
    {
    	if(count == n)
    	{
    		ans.push_back(str);
    		return;
    	}
    	for(int i = 0; i < n; ++i)
    	{
    		if(!visited[i])
    		{
    			if(i != 0 && s[i-1] == s[i] && visited[i-1])
    				continue;
    			visited[i] = true;
    			str.push_back(s[i]);
    			bt(s,count+1,visited);
    			str.pop_back();
    			visited[i] = false;
    		}
    	}
    }
};