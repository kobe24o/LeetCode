#include <unordered_map>
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    string shortestCompletingWord(string licensePlate, vector<string>& words) {
        unordered_map<char,int> m;
        for(char c : licensePlate)
        	if(isalpha(c))
        		m[tolower(c)]++;
        unordered_map<char,int> wc;
        int minLen = INT_MAX;
        bool flag;
        string ans;
        for(string word : words)
        {
        	wc.clear();
        	flag = true;
        	for(char c : word)
        		if(isalpha(c))
        			wc[c]++;
        	for(auto lpChar : m)
        	{
        		if(wc.find(lpChar.first) == wc.end() || wc[lpChar.first] < lpChar.second)
        		{
        			flag = false;
        			break;
        		}
        	}
        	if(flag)
        	{
        		if(word.size() < minLen)
        		{
        			minLen = word.size();
        			ans = word;
        		}
        	}
        }
        return ans;
    }
};
int main()
{
	vector<string> v = {"step", "steps", "stripe", "stepple"};
	Solution s;
	s.shortestCompletingWord("1s3 PSt",v);
}