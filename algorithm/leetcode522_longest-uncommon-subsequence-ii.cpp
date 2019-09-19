bool cmp(string &a, string &b) 
{
	if(a.size() == b.size())
	{
		for(int i = 0; i < a.size(); ++i)
		{
			if(a[i] != b[i])
				return a[i] < b[i];
		}
	}
	return a.size() < b.size();
}
class Solution {
public:
    int findLUSlength(vector<string>& strs) {
        sort(strs.begin(), strs.end(),cmp);
        string preStr = strs.back();
        bool same = false;
        for(auto it = strs.rbegin()+1; it != strs.rend(); ++it) 
        {
        	if(*it != preStr && same == false)
        		return preStr.size();
        	else if(*it == preStr)
        	{
        		same = true;
        		
        	}
            else if(*it != preStr && same == true)
            {
                if(it != strs.rend())
                {
                	same = false;
                	preStr = *it;
                }
                else
                	return strs.front().size();
            }
        }
	return -1;
    }
};
