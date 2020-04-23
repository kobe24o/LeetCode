#include<string>
#include<vector>
#include<algorithm>
#include<iostream>
#include<map>
using namespace std;

class Solution {
public:
    int findLUSlength(vector<string>& strs) {
        sort(strs.begin(), strs.end(),[&](auto a, auto b){
            return a.size() > b.size();//按长度排序
        });
        map<string,int> m;
        for(auto it = strs.begin(); it != strs.end(); ++it)
            m[*it]++;
        vector<string> uniq;
        for(auto it = m.begin(); it != m.end(); ++it)
        {
            if(it->second == 1)//次数一次的收集起来
                uniq.push_back(it->first);
        }
        sort(uniq.begin(), uniq.end(),[&](auto a, auto b){
            return a.size() > b.size();//按长度排序
        });
        for(auto it = uniq.begin(); it != uniq.end(); ++it)
        {
            if(!subSeq(strs,*it))
                return it->size();
        }
		return -1;
    }
    bool subSeq(vector<string> &strs, string& s)
    {
    	int len = s.size(), i, j;
    	bool flag;
    	for(auto it = strs.begin(); *it != s; ++it)
    	{  //str是从长到短的
    		flag = true;
    		for(i = 0,j = 0; i < len; ++i,++j)
    		{
    		    while(j < it->size() && (*it)[j] != s[i])
    		        j++;//长字符串中的字符不等
    		    if(j == it->size() && i < len)
                {
    		        flag = false;//不是子序
    		        break;
                }
    		    else if(i == len-1 && j <= it->size())
                {
    		        flag = true;
    		        break;
                }
    		}
    		if(flag)//是子序
    			break;
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