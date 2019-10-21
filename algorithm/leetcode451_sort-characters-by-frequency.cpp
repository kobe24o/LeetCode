struct cmp
{
    bool operator()(pair<char,int> &a, pair<char,int> &b)
    {
        return a.second < b.second;
    }
};
class Solution {
public:
    string frequencySort(string s) {
    	map<char,int> m;
        priority_queue<pair<char,int>, vector<pair<char,int>>, cmp> q;
        string ans;
        int n;
        for(int i = 0; i < s.size(); ++i)
        	m[s[i]]++;
        for(auto it = m.begin(); it != m.end(); ++it)
        {
        	q.push(*it);
        }
        while(!q.empty())
        {
            n = q.top().second;
            while(n--)
        	    ans.push_back(q.top().first);
        	q.pop();
        }
        return ans;
    }
};