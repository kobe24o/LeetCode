class Solution {
	int id;
	unordered_map<int, string> m;
public:
	Solution():id(0){}
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
    	m[++id] = longUrl;
        return "http://"+to_string(id);
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return m[stoi(shortUrl.substr(7,shortUrl.size()-7))];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));