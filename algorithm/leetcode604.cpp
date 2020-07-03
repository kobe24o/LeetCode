class StringIterator {
	string s;
	char cur;
	int count = 0, idx = 0;
public:
    StringIterator(string compressedString) {
    	s = compressedString;
    }
    
    char next() {
    	if(!hasNext()) return ' ';
        if(count>0)
    	{
    		count--;
    		return cur;
    	}
    	else//count=0
    	{
    		cur = s[idx];
            idx++;
            while(idx < s.size() && isdigit(s[idx]))
    		    count = count*10+(s[idx++]-'0');
            count--;//用掉了一个
    		return cur;
    	}
    }
    
    bool hasNext() {
    	return idx < s.size()||count;
    }
};