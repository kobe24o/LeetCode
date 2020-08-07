class Solution {
	vector<string> ans;
	int n;
public:
    vector<string> generateAbbreviations(string word) {
    	string empty;
    	n = word.size();
    	dfs(word, empty, 0, 0);
    	return ans;
    }
    void dfs(string& word, string& cur, int tailnum, int i)
    {	//tailnum 表示尾部现在有多少个连续的缩写，i 表示遍历到哪了
    	if(i == n)
    	{
    		if(tailnum > 0)
    			cur += to_string(tailnum);
    		ans.push_back(cur);
    		return;
    	}
    	int curlen = cur.size();
    	//当前的字符缩写
    	dfs(word, cur, tailnum+1, i+1);
    	cur.resize(curlen);//回溯
    	//不缩写，前面有数字的话需要加上
    	if(tailnum > 0)
    		cur += to_string(tailnum);
    	cur += word[i];//不缩写
    	dfs(word, cur, 0, i+1);//尾部缩写数量清0
    	cur.resize(curlen);//回溯
    }
};

class Solution {
public:
    vector<string> generateAbbreviations(string word) {
    	vector<string> ans;
    	int n = word.size(), i, j, k, zero;
    	for(i = 0; i < (1<<n); ++i)//每位字符两种状态，2进制
    	{
    		zero = 0;//0表示字符替换为缩写，记录连续的个数
    		k = 0;//遍历的word字符的位置
    		string w;
    		for(j = 0; j < n; ++j,++k)
    		{
    			if((i>>j)&1)//该位不替换
    			{
    				if(zero > 0)
    					w += to_string(zero);
    				w += word[k];
    				zero = 0;
    			}
    			else
    				zero++;
    		}
    		if(zero > 0)
    			w += to_string(zero);
    		ans.push_back(w);
    	}
    	return ans;
    }
};