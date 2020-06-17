class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
    	unordered_map<int,int> m;//等差数列结尾的数，最大长度
    	int maxlen = 1;
    	for(int i = 0, prev; i < arr.size(); ++i)
    	{
    		prev = arr[i]-difference;
    		if(m.count(prev))//前一个数
    			m[arr[i]] = m[prev] + 1;
    		else
    			m[arr[i]] = 1;
    		maxlen = max(maxlen, m[arr[i]]);
    	}
    	return maxlen;
    }
};