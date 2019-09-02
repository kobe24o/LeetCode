class Solution {
public:
    vector<string> letterCombinations(string digits) {
        string temp;
        vector<string> ans;
        unordered_map<char,vector<char> > v;
        v['2'] = {'a','b','c'};
        v['3'] = {'d','e','f'};
        v['4'] = {'g','h','i'};
        v['5'] = {'j','k','l'};
        v['6'] = {'m','n','o'};
        v['7'] = {'p','q','r','s'};
        v['8'] = {'t','u','v'};
        v['9'] = {'w','x','y','z'};
        bt(v,digits,temp,ans,0);
        return ans;
    }
    void bt(unordered_map<char,vector<char> > &v, string &digits, string temp, vector<string> &ans, int i)
    {
        if(i == digits.size())
        {
            ans.push_back(temp);
            return;
        }
        vector<char> ch = v[digits[i]];  
        for(auto it = ch.begin(); it != ch.end(); ++it)
        {
            temp.push_back(*it);
            bt(v,digits,temp,ans,i+1);
            temp.pop_back();
        }
    }
};