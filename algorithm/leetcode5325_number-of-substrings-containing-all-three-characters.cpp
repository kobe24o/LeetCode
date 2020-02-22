class Solution {
	vector<int> pa;
	vector<int> pb;
	vector<int> pc;
public:
    int numberOfSubstrings(string s) {
    	int i,x,y;
    	for(i = 0; i < s.size(); i++)
    	{
    		if(s[i] == 'a')
    			pa.push_back(i);
    		else if(s[i] == 'b')
    			pb.push_back(i);
    		else
    			pc.push_back(i);
    	}
    	if(pa.empty() || pb.empty() || pc.empty())
    		return 0;
    	int count = 0;
    	for(auto& idxa : pa)
    	{
    		x = bsfirst(idxa,pb);
    		y = bsfirst(idxa,pc);
    		if(x==-1 || y==-1)
    			continue;
    		count += s.size()-max(pb[x],pc[y]);
    	}
    	for(auto& idxb : pb)
    	{
    		x = bsfirst(idxb,pa);
    		y = bsfirst(idxb,pc);
    		if(x==-1 || y==-1)
    			continue;
    		count += s.size()-max(pa[x],pc[y]);
    	}
    	for(auto& idxc : pc)
    	{
    		x = bsfirst(idxc,pb);
    		y = bsfirst(idxc,pa);
    		if(x==-1 || y==-1)
    			continue;
    		count += s.size()-max(pb[x],pa[y]);
    	}
    	return count;
    }

	int bsfirst(int idx, vector<int>& v)
	{
		int l = 0, r = v.size()-1, mid;
		while(l <= r)
		{
			mid = l+((r-l)>>1);
			if(v[mid] < idx)
				l = mid+1;
			else if(v[mid] > idx)
			{
				if(mid == 0 || v[mid-1] < idx)
					return mid;
				else
					r = mid-1;
			}
		}
		return -1;
	}
};