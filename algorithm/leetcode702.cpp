/**
 * // This is the ArrayReader's API interface.
 * // You should not implement it, or speculate about its implementation
 * class ArrayReader {
 *   public:
 *     int get(int index);
 * };
 */

class Solution {
public:
    int search(const ArrayReader& reader, int target) {
    	if(target>=10000 || target <= -10000)
    		return -1;
        int l = 0, r = INT_MAX, mid, val;
        while(l <= r)
        {
        	mid = l+((r-l)>>1);
        	val = reader.get(mid);
        	if(val > target)
        		r = mid-1;
        	else if(val < target)
        		l = mid+1;
        	else
        		return mid;
        }
        return -1;
    }
};