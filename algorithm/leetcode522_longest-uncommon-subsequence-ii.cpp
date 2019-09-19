#include<string>
#include<vector>
#include<algorithm>
#include<iostream>
#include<map>
using namespace std;

bool cmp(string &a, string &b) 
{
	if(a.size() == b.size())
	{
		for(int i = 0; i < a.size(); ++i)
		{
			if(a[i] != b[i])
				return a[i] > b[i];
		}
	}
	return a.size() > b.size();
}
class Solution {
public:
    int findLUSlength(vector<string>& strs) {
        sort(strs.begin(), strs.end(),cmp);
        map<string,int> m;
        for(auto it = strs.begin(); it != strs.end(); ++it)
        {
            if(m.find(*it) == m.end())
                m[*it] = 1;
            else
                m[*it]++;
        }
        vector<string> uniq;
        for(auto it = m.begin(); it != m.end(); ++it)
        {
            if(it->second == 1)
                uniq.push_back(it->first);
        }
        sort(uniq.begin(), uniq.end(),cmp);
        for(auto it = uniq.begin(); it != uniq.end(); ++it)
        {
            if(!subSeq(strs,it))
                    return it->size();
        }
		return -1;
    }
    bool subSeq(vector<string> &strs, vector<string>::iterator it)
    {
    	int len = it->size(), i, j;
    	bool flag;
    	for(auto idx = strs.begin(); *idx != *it; ++idx)
    	{
    		flag = true;
    		for(i = 0,j = 0; i < len; ++i,++j)
    		{
    		    while(j < idx->size() && (*idx)[j] != (*it)[i])
    		        j++;
    		    if(j == idx->size() && i < len)
                {
    		        flag = false;
    		        break;
                }
    		    else if(i == len-1 && j <= idx->size())
                {
    		        flag = true;
    		        break;
                }
    		}
    		if(flag == true)
    			return flag;
    	}
    	return flag;
    }
};
 int main()
 {
 	Solution s;
 	vector<string> strs = {"aabbcc", "aabbcc","bc","bcc","aabbccc"};
 	cout << s.findLUSlength(strs) << endl;
 }