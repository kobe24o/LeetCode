class Solution {
public:
    int uniqueLetterString(string s) {
        int i, j, k, count = 0;
        for(j = 0; j < s.size(); ++j)
        {
        	i = j-1, k = j+1;
        	while(i>=0 && s[i] != s[j])
        		i--;
        	while(k<s.size() && s[j] != s[k])
        		k++;
        	count = (count+(j-i)*(k-j))%1000000007;
        }
        return count;
    }
};

class Solution {
public:
    int uniqueLetterString(string s) {
        int count = 0;
        unordered_map<char,set<int>> m;
        for(int i = 0; i < s.size(); ++i)
        {
            m[s[i]].insert(i);
        }
        int lenl, lenr;
        for(int i = 0; i < s.size(); ++i)
        {
            auto it = m[s[i]].find(i);
            if(it == m[s[i]].begin())
                lenl = i+1;
            else
            {
                auto itl = it;
                itl--;
                lenl = i-*(itl);
            }
            if(it == --m[s[i]].end())
                lenr = s.size()-i;
            else
            {
                it++;
                lenr = *(it)-i;
            }
            count = (count+lenl*lenr)%1000000007;
        }
        return count;
    }
};