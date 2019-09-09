class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        string q{"qwertyuiop"};
        string a{"asdfghjkl"};
        string z{"zxcvbnm"};
        vector<string> ans;
        int i, j, Q, A, Z;
        for(i = 0; i < words.size(); ++i)
        {
        	Q = A = Z = 0;
        	for(j = 0; j < words[i].size(); ++j)
        	{
        		if(q.find(tolower(words[i][j])) != string::npos)
        			++Q;
        		else if(a.find(tolower(words[i][j])) != string::npos)
        			++A;
        		else
        			++Z;
        	}      	
        	if(Q == words[i].size() || A == words[i].size()
        		|| Z == words[i].size())
        		ans.push_back(words[i]);
        }
        return ans;
    }
};