class HitCounter {
    int kick = 0;
    map<int,int> m;
public:
    /** Initialize your data structure here. */
    HitCounter() {

    }
    
    /** Record a hit.
        @param timestamp - The current timestamp (in seconds granularity). */
    void hit(int timestamp) {
        kick++;
        m[timestamp]++;
    }
    
    /** Return the number of hits in the past 5 minutes.
        @param timestamp - The current timestamp (in seconds granularity). */
    int getHits(int timestamp) {
        auto it = m.begin();
        while(it != m.end() && timestamp-it->first >= 300)//过期了
        {
            kick -= it->second;
            m.erase(it++);
        }
        return kick;
    }
};