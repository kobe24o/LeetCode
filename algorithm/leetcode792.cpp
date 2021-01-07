class Solution {
public:
    int numMatchingSubseq(string S, vector<string>& words) {
        vector<vector<int>> pos(26);
        for(int i = 0; i < S.size(); i++)
        {
            pos[S[i]-'a'].push_back(i);
        }
        int ans = 0;
        for(auto& w : words)
        {
            int maxpos = -1, j = 0;
            for( ; j < w.size(); j++)
            {
                int idx = w[j]-'a';
                auto it = lower_bound(pos[idx].begin(), pos[idx].end(), maxpos+1);
                if(it == pos[idx].end())
                    break;
                maxpos = *it;
            }
            if(j == w.size())
                ans++;
        }
        return ans;
    }
};