class Solution {
public:
    int maxProduct(vector<string>& words) {
        vector<int> num(words.size());
        int ans = 0, i = 0, j, temp;
        for(string& word : words)
        	num[i++] = str2num(word);
        for(i = 0; i < words.size(); ++i)
        	for(j = i+1; j < words.size(); ++j)
        	{
        		if((num[i]&num[j]) == 0)//数字的各个位上01（字符）都不相同
        		{
        			temp = words[i].length()*words[j].length();
        			ans = max(ans, temp);
        		}
        	}
    	return ans;
    }

    int str2num(string& s)
    {
    	int i = 0;
    	for(char& c : s)
    		i |= (1<<(c-'a'));//字符串中出现的字符转成int的各个位的状态
    	return i;
    }
};