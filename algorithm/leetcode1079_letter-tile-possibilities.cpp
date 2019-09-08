#include <string>
#include <algorithm>
#include <iostream>

using namespace std;
class Solution {
public:
    int numTilePossibilities(string tiles) {
        int kinds = 0;
        sort(tiles.begin(), tiles.end());
        for(int sublen = 1; sublen <= tiles.size(); ++sublen)
        {
            bt(tiles,kinds,0,tiles.size()-1,sublen,0);
        }       
        return kinds;
    }
    void bt(string tiles, int &kinds, int left, int right, int sublen, int curlen)
    {
        if(curlen == sublen)
            ++kinds;
        else
        {
            for(int i = left; i <= right; ++i)
            {
                if(i > left && tiles[i] == tiles[left])
                    continue;
                swap(tiles[left],tiles[i]);
                bt(tiles,kinds,left+1,right,sublen,curlen+1);
            }
        }   
    }
};
int main()
{
	Solution s;
	cout << s.numTilePossibilities("AAABBC");
	return 0;
}