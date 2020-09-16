class TopVotedCandidate {
	vector<int> winner;
	vector<int> T;
public:
    TopVotedCandidate(vector<int>& persons, vector<int>& times) {
    	int maxVotes = 0, winId = -1;
    	unordered_map<int,int> votes;
    	T = times;
    	for(int i = 0; i < persons.size(); ++i) 
    	{
    		votes[persons[i]]++;
    		if(votes[persons[i]] >= maxVotes)
    		{
    			winId = persons[i];
    			maxVotes = votes[persons[i]];
    		}
    		winner.push_back(winId);
    	}
    }
    
    int q(int t) {
    	int l = 0, r = T.size()-1, mid;
    	while(l <= r)//找小于等于我的最后一个时刻
    	{
    		mid = l +((r-l)>>1);
    		if(T[mid] > t)
    			r = mid-1;
    		else
    		{
    			if(mid == T.size()-1 || T[mid+1] > t)
    				return winner[mid];
    			else
    				l = mid+1;
    		}
    	}
    	return -1;
    }
};