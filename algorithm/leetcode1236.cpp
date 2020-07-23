/**
 * // This is the HtmlParser's API interface.
 * // You should not implement it, or speculate about its implementation
 * class HtmlParser {
 *   public:
 *     vector<string> getUrls(string url);
 * };
 */

class Solution {
public:
    vector<string> crawl(string startUrl, HtmlParser htmlParser) {
        unordered_set<string> visited;
        visited.insert(startUrl);
        queue<string> q;
        q.push(startUrl);
        vector<string> ans;
        string cur, domain;
        while(!q.empty())
        {
        	cur = q.front();
            ans.push_back(cur);
        	q.pop();
        	domain = getdomain(cur);
        	vector<string> sub = htmlParser.getUrls(cur);
        	for(string& link : sub)
        	{
        		if(getdomain(link) == domain && !visited.count(link))
        		{
        			q.push(link);
        			visited.insert(link);
        		}
        	}
        }
        return ans;
    }
    string getdomain(string& url) 
    {
    	auto it = find(url.begin()+7, url.end(), '/');
    	return string(url.begin(), it);
    }
};

class Solution {
    unordered_set<string> visited;
    vector<string> ans;
public:
    vector<string> crawl(string startUrl, HtmlParser htmlParser) {
        visited.insert(startUrl);
        dfs(startUrl, htmlParser);
        return ans;
    }
    void dfs(string& cur, HtmlParser& htmlParser)
    {
        ans.push_back(cur);
        string domain = getdomain(cur);
        vector<string> sub = htmlParser.getUrls(cur);
        for(string& link : sub)
        {
            if(getdomain(link) == domain && !visited.count(link))
            {
                visited.insert(link);
                dfs(link, htmlParser);
            }
        }
    }
    string getdomain(string& url) 
    {
        auto it = find(url.begin()+7, url.end(), '/');
        return string(url.begin(), it);
    }
};