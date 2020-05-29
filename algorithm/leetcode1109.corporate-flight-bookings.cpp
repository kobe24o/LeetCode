class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
    	vector<int> bk(n+2,0);
    	for(auto& b : bookings)
    	{
    		bk[b[0]] += b[2];
    		bk[b[1]+1] -= b[2];
    	}
    	for(int i = 2; i <= n; i++)
    		bk[i] += bk[i-1];
    	return vector<int> (bk.begin()+1, bk.end()-1);
    }
};