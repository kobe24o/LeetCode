class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        const int k = N+1;
        bool trustPeople [k] = {false};//你相信别人
        int beTrust[k] = {0};//被别人相信
        for(auto& v : trust)
        {
        	trustPeople[v[0]] = true;
        	beTrust[v[1]]++;
        }
        for(int i = 1; i <= N; ++i)
        	if(!trustPeople[i] && beTrust[i]==N-1)
        		return i;
    	return -1;
    }
};