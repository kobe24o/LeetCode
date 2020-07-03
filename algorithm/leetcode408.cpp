class Solution {
public:
    bool validWordAbbreviation(string word, string abbr) {
    	int i = 0, n = 0, j = 0;
    	while(i<word.size() && j < abbr.size())
    	{
    		n = 0;
            if(isdigit(abbr[j]))
            {   
                if(abbr[j]=='0')//"a","01"
                    return false;
                while(j < abbr.size() && isdigit(abbr[j]))
                    n = n*10+abbr[j++]-'0';
            }
    		i += n;
    		if(i<word.size() && j<abbr.size() && word[i] != abbr[j])
    			return false;
    		else if((i<word.size()&&j>=abbr.size())||(i>=word.size()&&j<abbr.size()))
    			return false;
            else if(i==word.size() && j==abbr.size())
                return true;//这里加一条，可能以数字结尾，下面++，出了循环，最后条件不成立
            i++,j++;
    	}
    	return i==word.size() && j==abbr.size();
    }
};