class Solution {
public:
    char findTheDifference(string s, string t) {
        unordered_map<char,int> m1;
        unordered_map<char,int> m2;
        int i;
        for(i = 0; i < s.size(); ++i)
        {
        	if(m1.find(s[i]) == m1.end())
        		m1[s[i]] = 1;
        	else
        		m1[s[i]]++;
        }
        for(i = 0; i < t.size(); ++i)
        {
        	if(m2.find(t[i]) == m2.end())
        		m2[t[i]] = 1;
        	else
        		m2[t[i]]++;
        }
        for(auto it = m2.begin(); it != m2.end(); ++it)
        {
        	auto iter = m1.find(it->first);
        	if(iter == m1.end() 
        		|| (iter != m1.end() && iter->second != it->second))
        		return it->first;
        }
        return 'a';
    }
};

class Solution {
public:
    char findTheDifference(string s, string t) {
        int i;
        char ch = 0;
        for(i = 0; i < s.size(); ++i)
        	ch ^= s[i]^t[i];
        ch ^= t[i];
        return ch;
    }
};

class Solution {
public:
    char findTheDifference(string s, string t) {
        int i,sum = 0;
        for(i = 0; i < s.size(); ++i)
        	sum += t[i]-s[i];
        sum += t[i];
        return (char)sum;
    }
};