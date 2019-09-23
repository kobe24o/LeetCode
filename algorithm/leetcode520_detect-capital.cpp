class Solution {
public:
    bool detectCapitalUse(string word) {
        if(word.length() <= 1)
        	return true;
        bool firstUpper;
        int i;
        if(word[0] >= 'A' && word[0] <= 'Z')
        	firstUpper = true;
        else
        	firstUpper = false;
        if(firstUpper == false)
        {
        	for(i = 1; i < word.size(); ++i)
        	{
        		if(!(word[i] >= 'a' && word[i] <= 'z'))
        			return false;
        	}
        	return true;
        }
        else	//firstUpper == true
        {
        	if(word[1] >= 'a' && word[1] <= 'z')
        	{
	        	for(i = 2; i < word.size(); ++i)
	        	{
	        		if(!(word[i] >= 'a' && word[i] <= 'z'))
	        			return false;
	        	}
	        	return true;
	        }
	        else//第二个字母大写
	        {
	        	for(i = 2; i < word.size(); ++i)
	        	{
	        		if(!(word[i] >= 'A' && word[i] <= 'Z'))
	        			return false;
	        	}
	        	return true;
	        }
        }

    }
};

class Solution {
public:
    bool detectCapitalUse(string word) {
        int uc = 0;
        for (int i = 0; i < word.size(); ++i) 
        {
            if (isupper(word[i])) 
            {
                if(uc < i)
                    return false;
                ++uc;
            }
        }       
        return uc == word.size() || uc <= 1;
    }
};