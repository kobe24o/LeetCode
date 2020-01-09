class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(), folder.end());
        vector<string> ans(1,folder[0]);
        string str = folder[0];
        bool issub = false;
        for(int i = 1; i < folder.size(); ++i)
        {
        	if(!issub)
        	{	
        		str = ans.back()+"/";
        		issub = true;
        	}
        	
    		if(folder[i].find(str) == folder[i].npos)
	        {
	        	ans.push_back(folder[i]);
	        	issub = false;
	        }       	      	
        }
        return ans;
    }
};

class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(), folder.end());
        vector<string> ans(1,folder[0]);
        string str = folder[0]+"/";
        for(int i = 1; i < folder.size(); ++i)
        {
        	while(i < folder.size() && folder[i].find(str) != folder[i].npos)
	        	i++;
	        if(i < folder.size())
	        {
	        	ans.push_back(folder[i]);
	        	str = ans.back()+"/";
	        }
        }
        return ans;
    }
};