/**
 * // This is Sea's API interface.
 * // You should not implement it, or speculate about its implementation
 * class Sea {
 *   public:
 *     bool hasShips(vector<int> topRight, vector<int> bottomLeft);
 * };
 */

class Solution {
	int sum = 0;
public:
    int countShips(Sea sea, vector<int> topRight, vector<int> bottomLeft) {
    	if(!sea.hasShips(topRight, bottomLeft))
    		return 0;
    	int xmid = (topRight[0] + bottomLeft[0])/2;
        int ymid = (topRight[1] + bottomLeft[1])/2;
        if(topRight == bottomLeft)
    		return ++sum;
    	else if(bottomLeft[0] == topRight[0])
    	{
    		countShips(sea, {xmid, ymid}, bottomLeft);
	        countShips(sea, topRight, {xmid, ymid+1});
    	}
        else if(bottomLeft[1] == topRight[1])
        {
        	countShips(sea, {xmid, ymid}, bottomLeft);
	        countShips(sea,  topRight, {xmid+1, ymid});
        }
        else
        {
	        countShips(sea, {xmid, ymid}, bottomLeft);
	        countShips(sea,  {topRight[0], ymid}, {xmid+1, bottomLeft[1]});
	        countShips(sea, {xmid, topRight[1]}, {bottomLeft[0],ymid+1});
	        countShips(sea, topRight, {xmid+1, ymid+1});
	    }
        return sum;
    }
};