class Solution {
public:
    int findString(vector<string>& words, string s) {
    	vector<pair<string,int>> w_id;
    	for(int i = 0; i < words.size(); ++i)
    		if(words[i] != "")
    			w_id.push_back({words[i],i});
    	int l = 0, r = w_id.size()-1, mid;
    	while(l <= r)
    	{
    		mid = l+((r-l)>>1);
    		if(s < w_id[mid].first)
    			r = mid-1;
    		else if(s > w_id[mid].first)
    			l = mid+1;
    		else
    			return w_id[mid].second;
    	}
    	return -1;
    }
};
class Solution {
public:
    int findString(vector<string>& words, string s) {
    	int l = 0, r = words.size()-1, mid;
    	while(l <= r)
    	{
    		while(l <= r && words[l]=="")
    			l++;
    		while(l <= r && words[r]=="")
    			r--;
    		mid = l+((r-l)>>1);
    		if(s < words[mid])
    			r = mid-1;
    		else if(s > words[mid])
    			l = mid+1;
    		else
    			return mid;
    	}
    	return -1;
    }
};