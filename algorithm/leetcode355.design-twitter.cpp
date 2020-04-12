struct cmp
{
    bool operator()(const vector<int> a, const vector<int> b) const
    {
        return a[0] < b[0];
    }
};
class Twitter {
    unordered_map<int,unordered_set<int>> m;//id，关注的人
    set<vector<int>,cmp> tweet;//time, 推文id，用户id
    int time = 0;
    int count;
    vector<int> ans;
public:
    /** Initialize your data structure here. */
    Twitter() {

    }
    
    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        tweet.insert({time++, tweetId, userId});
    }
    
    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
        count = 10;
        ans.clear();
        for(auto it = tweet.rbegin(); it != tweet.rend() && count; ++it)
        {
            if((*it)[2]==userId || m[userId].count((*it)[2]))
            {
                ans.push_back((*it)[1]);
                count--;
            }
        }
        return ans;
    }
    
    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        m[followerId].insert(followeeId);
    }
    
    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
        m[followerId].erase(followeeId);
    }
};