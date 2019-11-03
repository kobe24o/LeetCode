class Solution {
public:
    vector<int> powerfulIntegers(int x, int y, int bound) {
        int i, j, res;
        unordered_set<int> s;
        int Maxi = (x != 1) ? log(bound)/log(x)+1 : bound/2;
        int Maxj = (y != 1) ? log(bound)/log(y)+1 : bound/2;
        for(i = 0; i <= Maxi; i++)
        {
        	for(j = 0; j <= Maxj; j++)
        	{
        		res = pow(x,i)+pow(y,j);
        		if(res <= bound)
        			s.insert(res);
        	}
        }        
        return vector<int> (s.begin(),s.end());
    }
};

class Solution {
public:
    vector<int> powerfulIntegers(int x, int y, int bound) {
        int i = 0, j = 0, res;
        unordered_set<int> s;
        int powx, powy;
        for(i = 0; (powx = pow(x,i)) <= bound; i++)
        {
        	for(j = 0; (powy = pow(y,j)) <= bound; j++)
        	{
        		res = powx+powy;
        		if(res <= bound)
        			s.insert(res);
                if(y == 1)
                    break;
        	}
            if(x == 1)
                break;
        }        
        return vector<int> (s.begin(),s.end());
    }
};