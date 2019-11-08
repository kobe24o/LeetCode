class Solution {
	vector<vector<string>> ans;
public:
    vector<vector<string>> partition(string s) { 
    	vector<string> v;
        bt(s,v,0);//回溯算法
        return ans;
    }
    void bt(string &s, vector<string> &v, int i)
    {
    	if(i == s.size())//起始位置到达末尾，结束
    	{
    		ans.push_back(v);
    		return;
    	}
    	for(int k = i; k < s.size(); k++)//从起点i往后遍历
    	{
    		if(ispalindrome(s,i,k))//如果是回文
    		{
    			v.push_back(s.substr(i,k-i+1));//加入
    			bt(s,v,k+1);//对k后面的继续递归处理
    			v.pop_back();//回溯，还原现场
    		}
    	}
    }

	bool ispalindrome(string &str, int i, int j)
	{	//判断子串是否是回文串
		while(i < j)
			if(str[i++] != str[j--])
				return false;
		return true;
	}
};