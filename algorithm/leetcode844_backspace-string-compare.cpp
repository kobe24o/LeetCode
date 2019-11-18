#include <iostream>
#include<string>
using namespace std;
class Solution {
public:
    bool backspaceCompare(string S, string T) {
        process(S);
        process(T);
        int i, j;
        for(i = 0,j = 0; i < S.size() && j < T.size(); i++,j++)
        {
        	while(i < S.size() && S[i] == '#')
        		i++;
        	while(j < T.size() && T[j] == '#')
        		j++;
        	if((i < S.size() && j < T.size() && S[i] != T[j])
        	    || (i < S.size() && j >= T.size())
        	    || (j < T.size() && i >= S.size()))
        		return false;
        }
        while(i < S.size() && S[i] == '#')
        	i++;
        while(j < T.size() && T[j] == '#')
        	j++;
        return i>=S.size() && j>=T.size();
    }

    void process(string &s)
    {
    	int i, j;
    	for(j = 0; j < s.size(); ++j)
    	{
    		i = j-1;
    		while(j < s.size() && s[j] == '#')
    		{
    			while(i >= 0 && s[i] == '#')
    				i--;
    			if(i >= 0)
    				s[i] = '#';
    			++j;
    		}
    	}
    }
};

int main()
{
	Solution s;
	std::cout << s.backspaceCompare("isfcow#","isfco#w#");
}


class Solution {
public:
    bool backspaceCompare(string s, string t) {
        return process(s) == process(t);
    }
    
    string process(string &s) 
    {
        vector<char> v;
        for(char c : s) 
        {
            if(c == '#')
            {
                if (!v.empty()) 
                    v.pop_back();
            }
            else 
                v.push_back(c);
        }
        return string(v.begin(), v.end());
    }
};