class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> ans;
        string line;
        int i, width = 0, wc;
        for(i = 0; i < words.size(); ++i)
        {
        	if(line.empty())
        	{
        		line = words[i];
        		width = words[i].size();
        		wc = 1;
        	}
        	else
        	{
        		if(width+1+words[i].size() <= maxWidth)
        		{
        			line += " "+words[i];
        			width += 1+words[i].size();
        			// wordwith += words[i].size();
        			wc++;
        		}
        		else//超了，放不下i
        		{
        			process(wc,line,maxWidth,width);
        			ans.push_back(line);
    				line = "";
    				width = wc = 0;
    				i--;
        		}
        	}
        }
        line += string(maxWidth-width,' ');
        ans.push_back(line);
        return ans;
    }

    void process(int wc, string& line, int maxWidth, int width)
    {
    	if(wc == 1)
    	{
    		line += string(maxWidth-width,' ');
    		return;
    	}
    	int space = maxWidth - width;
    	int n = space/(wc-1);
    	int pos = wc-1;
    	for(int i = line.size()-1; i >= 0; --i)
    	{
    		if(line[i] == ' ')
    		{
    			line.insert(i,n,' ');
    			space -= n;
    			pos--;
    			if(pos > 0 && space%pos == 0)
    				n = space/pos;
    		}
    	}
    }
};