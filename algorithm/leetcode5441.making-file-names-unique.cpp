class Solution {
public:
    vector<string> getFolderNames(vector<string>& names) {
    	unordered_map<string,int> m;
    	vector<string> ans(names.size());
        int num;
    	for(int i = 0; i < names.size(); ++i)
    	{
    		if(!m.count(names[i]))//没有出现过
    		{
    			m[names[i]]++;//计数+1
    			ans[i] = names[i];//答案不变
    		}
    		else
    		{	//出现过该单词
                num = m[names[i]];//读取当前应该的计数
    			while(m.count(names[i]+"("+to_string(num)+")"))//出现过了
                    num++;//数字增加，直到没有出现过
                ans[i] = names[i]+"("+to_string(num)+")";//写入答案
    			m[names[i]] = num+1;//更新计数
    			m[ans[i]]++;
    		}
    	}
    	return ans;
    }
};