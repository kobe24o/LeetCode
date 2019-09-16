class Solution {
public:
    vector<int> diStringMatch(string S) {
        vector<int> ans;
        int i = 0, j = S.size(), k;
        for(k = 0; k < S.size(); ++k)
        {
        	if(S[k] == 'I')
        		ans.push_back(i++);
        	else
        		ans.push_back(j--);
        }
        ans.push_back(i);//or j
        return ans;
    }
};