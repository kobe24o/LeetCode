class Solution {
public:
    string similarRGB(string color) {
    	string s1 = color.substr(1,2);
    	string s2 = color.substr(3,2);
    	string s3 = color.substr(5,2);
    	int a = stoi(s1,0,16);//转成10进制
    	int b = stoi(s2,0,16);
    	int c = stoi(s3,0,16);
    	vector<string> num = {"00","11","22","33","44","55","66","77","88",
    							"99","aa","bb","cc","dd","ee","ff"};
		int i, j, k, x, y, z, maxsimilarity = INT_MIN, sim;
		string ans;
		for(i = 0; i < 16; ++i)
			for(j = 0; j < 16; ++j)
				for(k = 0; k < 16; ++k)
				{
					x = stoi(num[i],0,16);//转成10进制
			    	y = stoi(num[j],0,16);
			    	z = stoi(num[k],0,16);
			    	sim = -(a-x)*(a-x)-(b-y)*(b-y)-(c-z)*(c-z);
			    	if(sim > maxsimilarity)
			    	{
			    		maxsimilarity = sim;
			    		ans = "#"+num[i]+num[j]+num[k];
			    	}
				}
		return ans;
    }
};

class Solution {
public:
    string similarRGB(string color) {
    	string s1 = color.substr(1,2);
    	string s2 = color.substr(3,2);
    	string s3 = color.substr(5,2);
    	int a = stoi(s1,0,16);//转成10进制
    	int b = stoi(s2,0,16);
    	int c = stoi(s3,0,16);
    	vector<string> num = {"00","11","22","33","44","55","66","77","88",
    							"99","aa","bb","cc","dd","ee","ff"};
		int maxsimilarity1 = INT_MIN, maxsimilarity2 = INT_MIN,
			maxsimilarity3 = INT_MIN, sim1, sim2, sim3;
		string ans1, ans2, ans3;
		for(int i = 0, n; i < 16; ++i)
		{
			n = stoi(num[i],0,16);//转成10进制
	    	sim1 = -(a-n)*(a-n);
	    	sim2 = -(b-n)*(b-n);
	    	sim3 = -(c-n)*(c-n);
	    	if(sim1 > maxsimilarity1)
	    	{
	    		maxsimilarity1 = sim1;
	    		ans1 = num[i];
	    	}
	    	if(sim2 > maxsimilarity2)
	    	{
	    		maxsimilarity2 = sim2;
	    		ans2 = num[i];
	    	}
	    	if(sim3 > maxsimilarity3)
	    	{
	    		maxsimilarity3 = sim3;
	    		ans3 = num[i];
	    	}
		}
		return '#'+ans1+ans2+ans3;
    }
};