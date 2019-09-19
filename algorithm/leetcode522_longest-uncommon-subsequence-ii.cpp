#include<string>
#include<vector>
#include<algorithm>
#include<iostream>
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
        string preStr = strs.front();
        bool same = false;
        for(auto it = strs.begin()+1; it != strs.end(); ++it) 
        {
        	if(*it != preStr && same == false && !subSeq(strs, it))
        		return preStr.size();
        	else if(*it == preStr)
        	{
        		same = true;
        		
        	}
            else if(*it != preStr && same == true)
            {
                if(it != strs.end()-1)
                {
                	same = false;
                	preStr = *it;
                }
                else
             
                	if(!subSeq(strs,it))
                		return it->size();
            
            }
        }
		return -1;
    }
    bool subSeq(vector<string> &strs, vector<string>::iterator it)
    {
    	int len = it->size(), i;
    	bool flag = false;
    	for(auto idx = strs.begin(); idx != it; ++idx)
    	{
    		flag = true;
    		for(i = 0; i < len; ++i)
    		{
    			if(idx->find((*it).substr(i,1)) == string::npos)
    			{
    				flag = false;
    				break;
    			}
    			// else
    			// 	flag = true;
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
 	vector<string> strs = {"aaa","aaa","cb","abc"};
 	cout << s.findLUSlength(strs) << endl;
 }