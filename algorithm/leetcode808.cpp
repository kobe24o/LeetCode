class Solution {
public:
    double soupServings(int N) {
    	unordered_map<int,unordered_map<int,double>> dp, temp;
        if(N >= 4800) return 1;
    	dp[N][N] = 1.0;
    	double prob = 0.0, p, pp;
    	vector<vector<int>> delta = {{100,0},{75,25},{50,50},{25,75}};
    	int A, B, nA, nB, i, idx;
        while(!dp.empty())
        {
            for(auto& item1 : dp)
            {	
                A = item1.first;
                for(auto& item2 : item1.second)
                {
                    B = item2.first;
                    p = item2.second;
                    if(A == 0)
                    {
                        if(B == 0)
                            prob += p/2.0;
                        else if(B > 0)
                            prob += p;
                    }
                    else
                    {
                        if(B == 0)
                            continue;
                        for(i = 0; i < 4; i++)
                        {
                            nA = max(0, A-delta[i][0]);
                            nB = max(0, B-delta[i][1]);
                            temp[nA][nB] += p*0.25;
                        }
                    }
                }
            }
            dp.swap(temp);
            temp.clear();
        }
    	return prob;
    }
};