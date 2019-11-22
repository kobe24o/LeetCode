class Solution {
public:
    bool isSubsequence(string s, string t) {
        if(s.size() > t.size())
        	return false;
        int i = 0, j = 0;
        for( ; i < s.size() && j < t.size(); ++j)
        {
        	if(s[i] == t[j])
        		i++;
        }
        return (i==s.size());
    }
};

class Solution {
	int L, R, mid;
public:
    bool isSubsequence(string s, string t) {
        if(s.size() > t.size())
        	return false;
        vector<vector<int>> m(26);//存储t中字符对应的位置
        int i, j = 0;
        for(i = 0; i < t.size(); ++i)
        {
        	m[t[i]-'a'].push_back(i);
        }
        for(i = 0; i < s.size() && j < t.size(); ++i)
        {
        	j = binarysearch(m[s[i]-'a'], j);
        	if(j == -1)
        		return false;
        	j++;
        }
        return (i==s.size());
    }

    int binarysearch(vector<int>& v, int &pos)//找值>=pos的第一个
    {
    	L = 0, R = v.size()-1;
    	while(L <= R)
    	{
    		mid = L+((R-L)>>1);
    		if(v[mid] >= pos)
    		{
    			if(mid==0 || v[mid-1] < pos)
    				return v[mid];
    			else
    				R = mid-1;
    		}
    		else if(v[mid] < pos)
    			L = mid+1;
    	}
    	return -1;
    }
};