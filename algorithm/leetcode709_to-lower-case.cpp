class Solution {
public:
    string toLowerCase(string str) {
        char ch;
        for(int i = 0; i < str.size(); ++i)
        {
        	if(str[i] >= 'A' && str[i] <= 'Z')
        	{
        		ch = tolower(str[i]);
        		str[i] = ch;
        	}
        }
        return str;
    }
};

class Solution {
public:
    string toLowerCase(string str) {
        for(int i = 0; i < str.size(); ++i)
        {
        	if(str[i] >= 'A' && str[i] <= 'Z')
        	{
        		str[i] += 32;
        	}
        }
        return str;
    }
};