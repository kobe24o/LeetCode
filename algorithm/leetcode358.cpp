class Solution {
    struct cmp
    {
        bool operator()(pair<char, int>& a, pair<char, int>& b){
            if(a.second == b.second)
                return a.first < b.first;
            return a.second < b.second;//数量多的优先
        }
    };
public:
    string rearrangeString(string s, int k) {
    	if(k <= 1) return s;
        unordered_map<char, int> count;
        for(int i = 0; i < s.size(); i++) 
        	count[s[i]]++;
        priority_queue<pair<char, int>, vector<pair<char,int>>, cmp> q;
        for(auto& c : count)
            q.push(c);
        string ans;
        while(q.size() >= k)
        {
        	vector<pair<char, int>> temp;
        	int t = k;
        	while(t--)
        	{
        		auto tp = q.top();
        		q.pop();
        		int num = tp.second;
        		char ch = tp.first;
        		ans += ch;
        		num--;
        		if(num != 0)
        			temp.push_back({ch, num});
        	}
        	for(auto& char_num : temp)
        		q.push(char_num);
        }
        while(!q.empty())
        {
            if(q.top().second == 1)
            {
                ans += q.top().first;
                q.pop();
            }
            else
                return "";
        }
        return ans;
    }
};