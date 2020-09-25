class TimeMap {
	unordered_map<string,map<int,string>> m;
public:
    /** Initialize your data structure here. */
    TimeMap() {

    }
    
    void set(string key, string value, int timestamp) {
    	m[key][timestamp] = value;
    }
    
    string get(string key, int timestamp) {
    	if(m.find(key) == m.end())
    		return "";
    	auto it = m[key].upper_bound(timestamp);
    	if(it == m[key].begin())
    		return "";
    	return (--it)->second;
    }
};