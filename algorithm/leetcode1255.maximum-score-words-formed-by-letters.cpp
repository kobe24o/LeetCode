class Solution {
	int maxscore = 0;
public:
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
    	int n = words.size(), i;
    	vector<int> count(26,0);
		for(i = 0; i < letters.size(); ++i)
			count[letters[i]-'a']++;
		dfs(words, count, score, 0, 0);
		return maxscore;
    }

    void dfs(vector<string>& words, vector<int>& count, vector<int>& score, int i, int sc)
    {
    	if(i == words.size())
    	{
            if(canAdd(count))
    		    maxscore = max(maxscore, sc);
    		return;
    	}
        for(int j = 0; j < words[i].size(); ++j)
        {
            sc += score[words[i][j]-'a'];
            count[words[i][j]-'a']--;
        }
        dfs(words, count, score, i+1, sc);
        for(int j = 0; j < words[i].size(); ++j)
        {
            sc -= score[words[i][j]-'a'];
            count[words[i][j]-'a']++;
        }
        dfs(words, count, score, i+1, sc);
    }

	bool canAdd(vector<int>& count)
	{
		for(int i = 0; i < 26; ++i)
		{
			if(count[i] < 0)
				return false;
		}
		return true;
	}
};