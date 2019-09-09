#include <iostream>
#include <cstring>
using namespace std;
class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        int count[26] = {0}, wordcount[26];
        int i, j, k, ans = 0;
        bool hasthisword;
        for(i = 0; i < chars.size(); ++i)
        {
        	count[chars[i]-'a']++;
        }
        for(i = 0; i < words.size(); ++i)
        {
        	hasthisword = true;
        	memset(wordcount,0,sizeof(int)*26);
        	for(j = 0; j < words[i].size(); ++j)
        	{
        		wordcount[words[i][j]-'a']++;
        	}
        	for(j = 0; j < 26; ++j)
        	{
        		if(wordcount[i] > count[i])
        		{
        			hasthisword = false;
        			break;
        		}
        	}
        	if(hasthisword)
        		ans += words[i].size();
        }
        return ans;
    }
};
int main()
{
	Solution s;
	vector<string> words = {"cat","bt","hat","tree"};
	string chars("atach");
	cout << s.countCharacters(words, chars);
	return 0;
}