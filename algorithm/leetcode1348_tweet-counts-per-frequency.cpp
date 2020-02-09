class TweetCounts {
	unordered_map<string,set<int>> m;
public:
    TweetCounts() {
        
    }
    
    void recordTweet(string tweetName, int time) {
        m[tweetName].insert(time);
    }
    
    vector<int> getTweetCountsPerFrequency(string freq, string tweetName, int startTime, int endTime) {
        int gap;
        if(freq == "minute")
        	gap = 60;
        else if(freq == "hour")
        	gap = 3600;
        else//"day"
        	gap = 3600*24;
        if(!m.count(tweetName))
        	return {};
        vector<int> ans;
        int count, end_t;
        while(startTime <= endTime)
        {
        	count = 0;
        	end_t = min(endTime, startTime + gap-1);
        	auto beg = m[tweetName].lower_bound(startTime);
        	auto end = m[tweetName].upper_bound(end_t);
        	for(auto it = beg; it != end; it++)
        	{
        		count++;
        	}
        	ans.push_back(count);
        	startTime += gap;
        }
        return ans;
    }
};