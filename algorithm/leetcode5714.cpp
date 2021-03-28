class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string,string> m;
        for(auto& k : knowledge)
            m[k[0]] = k[1];
        string ans, key;
        bool left = false;
        for(auto c : s)
        {
            if(c == '(')
            {
                left = true;
                continue;
            }
            else if(c == ')')
            {
                left = false;
                if(m.find(key) != m.end())
                    ans += m[key];
                else
                    ans += '?';
                key = "";
                continue;
            }
            if(left)
                key += c;
            else
                ans += c;
        }
        return ans;
    }
};