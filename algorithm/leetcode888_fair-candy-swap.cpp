class Solution {
public:
    vector<int> fairCandySwap(vector<int>& A, vector<int>& B) {
        int s1 = 0, s2 = 0, s;
        for(int &i : A)
        	s1 += i;
        for(int &i : B)
        	s2 += i;
        s = s1 + s2;
        for(int &i : A)
        	for(int &j : B)
        		if(s1-i+j == s/2)
        			return {i,j};
		return {};
    }
};

class Solution {
public:
    vector<int> fairCandySwap(vector<int>& A, vector<int>& B) {
        int s1 = 0, s2 = 0, s;
        unordered_set<int> set;
        for(int &i : A)
        	s1 += i;
        for(int &i : B)
        {
        	s2 += i;
        	set.insert(i);
        }
        s = s1 + s2;
        for(int &i : A)
    		if(set.count(s/2 - s1 + i))
    			return {i,s/2 - s1 + i};
		return {};
    }
};