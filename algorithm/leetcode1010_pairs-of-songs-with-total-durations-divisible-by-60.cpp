class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int t[60] = {0};//求余后的秒数，对应的歌曲数
        for(int &s : time)
        	t[s%60]++;
        int ans = 0;
        ans += t[0]*(t[0]-1)/2 + t[30]*(t[30]-1)/2;
        for(int i = 1; i < 30; ++i)
        {
        	ans += t[i]*t[60-i];
        }
        return ans;
    }
};

class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int i, j, sum = 0;
        for(i = 0; i < time.size()-1; ++i)
        	for(j = i+1; j < time.size(); ++j)
        		if((time[i]+time[j])%60 == 0)
        			sum++;
		return sum;
    }
};