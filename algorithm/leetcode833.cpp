class Solution {
public:
    string findReplaceString(string S, vector<int>& indexes, vector<string>& sources, vector<string>& targets) {
        int n = S.size(), i = 0, k, len;
        unordered_map<int,int> m;
        for(i = 0; i < indexes.size(); i++) 
        {
            m[indexes[i]] = i;//原始数值 --> 对应的原始序号
        }
        sort(indexes.begin(), indexes.end());
        for(i = int(indexes.size())-1; i >= 0; i--)
        {   //从大的序号开始替换，不需考虑序号变化
            k = m[indexes[i]];
            len = sources[k].size();
            if(S.substr(indexes[i], len) == sources[k])
            {
                S.replace(indexes[i], len, targets[k]);
            }
        }
        return S;
    }
};