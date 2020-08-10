class Solution {
public:
    int wordsTyping(vector<string>& sentence, int rows, int cols) {
    	int n = sentence.size(), i, j, len = 0, ans = 0;
    	vector<int> wordlen(sentence.size());
    	for(i = 0; i < n; ++i)
    	{
    		len += sentence[i].size()+1;
    		wordlen[i] = sentence[i].size();
    	}
    	len--;//一个句子的长度
    	if(cols >= len)
    	{
	    	ans += cols/(len+1)*rows;//带一个空格能放下几个句子
	    	cols = cols%(len+1);//只用考虑剩余的不完整空格
	    	if(cols%(len+1) == len)//不带空格正好还有一个位置
	    	{
	    		ans += rows;
	    		return ans;
	    	}
	    }

    	vector<int> dp(n);//每行从i单词开始填，可以填到哪个单词
    	for(i = 0 ;i < n; i++)
    	{
    		j = i;
    		len = 0;
    		while(len+wordlen[j] <= cols)
    		{
    			len += wordlen[j]+1;//+1是空格
    			j = (j+1)%n;
    		}
    		dp[i] = j;//i单词开始放，放完该行可以到j单词（不含j）
    	}
    	for(i = 0, j = 0; i < rows; i++)
    	{
    		if(dp[j] < j)//放满了一行，dp[j]跑到前面去了
    			ans++;
    		j = dp[j];
    	}
    	return ans;
    }
};