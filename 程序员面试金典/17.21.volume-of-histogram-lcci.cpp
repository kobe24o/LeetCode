class Solution {
public:
    int trap(vector<int>& h) {
    	if(h.empty())
            return 0;
    	stack<int> s;//存储idx
    	int sum = 0, tp;
    	for(int i = 0; i < h.size(); ++i)
    	{
    		while(!s.empty() && h[s.top()] < h[i])
    		{
    			tp = s.top();
    			s.pop();
    			if(s.empty())
    				break;
    			sum += (i-s.top()-1)*(min(h[i],h[s.top()])-h[tp]);
    		}
    		s.push(i);
    	}
    	return sum;
    }
};
class Solution {
public:
    int trap(vector<int>& h) {
        if(h.empty())
            return 0;
    	vector<int> L(h.size());
    	vector<int> R(h.size());
    	int Lmax=h[0],Rmax=h[h.size()-1];
    	for(int i = 0; i < h.size(); ++i)
    	{
    		Lmax = max(Lmax, h[i]);
    		L[i] = Lmax;
    	}
    	for(int i = h.size()-1; i >= 0; --i)
		{
			Rmax = max(Rmax, h[i]);
			R[i] = Rmax;
    	}
    	int sum = 0;
    	for(int i = 0; i < h.size(); ++i)
    		sum += min(L[i],R[i])-h[i];
    	return sum;
    }
};
class Solution {
public:
    int trap(vector<int>& h) {
    	if(h.empty())
    		return 0;
    	int i = 0, j = h.size()-1, sum = 0;
    	int Lmax = 0, Rmax = 0;
    	while(i < j)
    	{
    		if(h[i] <= h[j])
    		{
    			h[i] >= Lmax ? Lmax = h[i] : sum+=Lmax-h[i];
    			++i;
    		}
    		else
    		{
    			h[j] >= Rmax ? Rmax = h[j] : sum+=Rmax-h[j];
    			--j;
    		}
    	}
    	return sum;
    }
};