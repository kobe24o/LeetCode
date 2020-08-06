/**
 * // This is the ArrayReader's API interface.
 * // You should not implement it, or speculate about its implementation
 * class ArrayReader {
 *   public:
 *     // Compares 4 different elements in the array
 *     // return 4 if the values of the 4 elements are the same (0 or 1).
 *     // return 2 if three elements have a value equal to 0 and one element has value equal to 1 or vice versa.
 *     // return 0 : if two element have a value equal to 0 and two elements have a value equal to 1.
 *     int query(int a, int b, int c, int d);
 *
 *     // Returns the length of the array
 *     int length();
 * };
 */

class Solution {
	unordered_map<int, vector<vector<int>>> m;
public:
    int guessMajority(ArrayReader &reader) {
        m[4] = {{0, 0, 0, 0},{1, 1, 1, 1}};
		m[2] = {{0, 0, 0, 1},{0, 0, 1, 0},{0, 1, 0, 0},{1, 0, 0, 0},
        		{0, 1, 1, 1},{1, 0, 1, 1},{1, 1, 0, 1},{1, 1, 1, 0}};
		m[0] = {{0, 0, 1, 1},{1, 0, 0, 1},{0, 1, 0, 1},
        		{0, 1, 1, 0},{1, 0, 1, 0},{1, 1, 0, 0}};
        int n = reader.length(), i, j;
        int maxcount = -1, idx, state;
        vector<int> zero_one(2,0);
        vector<vector<int>> count(n,vector<int>(2, 0));
        for(i = 0; i <= n-4; ++i)
        {
        	state = reader.query(i,i+1,i+2,i+3);
        	for(auto& si : m[state])
        	{
        		count[i][si[0]]++;
        		zero_one[si[0]]++;
        		count[i][si[1]]++;
        		zero_one[si[1]]++;
        		count[i][si[2]]++;
        		zero_one[si[2]]++;
        		count[i][si[3]]++;
        		zero_one[si[3]]++;
        	}
        }
        if(zero_one[0] == zero_one[1])
        	return -1;
        if((zero_one[0] > zero_one[1]))
        {
        	for(int i = 0; i < n; ++i)
        	{
        		if(count[i][0] > maxcount)
        		{
        			maxcount = count[i][0];
        			idx = i;
        		}
        	}
        }
        else
        {
        	for(int i = 0; i < n; ++i)
        	{
        		if(count[i][1] > maxcount)
        		{
        			maxcount = count[i][1];
        			idx = i;
        		}
        	}
        }
        return idx;
    }
};