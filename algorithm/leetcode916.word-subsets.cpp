class Solution {
public:
    vector<string> wordSubsets(vector<string>& A, vector<string>& B) {
    	vector<int> countB(26,0);
    	for(auto& bi : B)
    	{
            vector<int> countb(26,0);
            for(char ch : bi)
    			countb[ch-'a']++;
            for(int i = 0; i < 26; ++i)
                countB[i] = max(countB[i],countb[i]);
        }

    	vector<string> ans;
    	bool ok;
    	for(auto& Ai : A)
    	{
            vector<int> countai(26,0);
    		ok = true;
    		for(char ch : Ai)
                countai[ch-'a']++;
    		for(int i = 0; i < 26; ++i)
            {
                if(countai[i] < countB[i])
                {
                    ok = false;
                    break;
                }
            }
            if(ok)
    			ans.push_back(Ai);
    	}
    	return ans;
    }
};