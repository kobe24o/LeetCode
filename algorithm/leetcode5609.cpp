class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        unordered_set<char> s(allowed.begin(), allowed.end());
        int ans = 0;
        for(int i = 0; i < words.size(); ++i)
        {
            bool flag = true;
            for(int j = 0; j < words[i].size(); ++j)
            {
                if(!s.count(words[i][j]))
                {
                    flag = false;
                    break;
                }
            }
            if(flag)
                ans++;
        }
        return ans;
    }
};
