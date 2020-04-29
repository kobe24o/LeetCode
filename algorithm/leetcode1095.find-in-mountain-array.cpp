/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int target, MountainArray &mArr) {
        int n = mArr.length(), l = 0, r = n-1, high;
        int lval, rval, mid, midval, mid1, midval1;
        while(l < r)
        {
            mid = l+((r-l)>>1);
            midval = mArr.get(mid);
            midval1 = mArr.get(mid+1);
            if(midval < midval1)
                l = mid+1;
            else
                r = mid;
        }
        high = l;
        l = 0; r = high;
        while(l <= r)
        {
            mid = l+((r-l)>>1);
            midval = mArr.get(mid);
            if(midval == target)
                return mid;
            else if(midval > target)
                r = mid-1;
            else
                l = mid+1;
        }
        l = high+1, r = n-1;
        while(l <= r)
        {
            mid = l+((r-l)>>1);
            midval = mArr.get(mid);
            if(midval == target)
                return mid;
            else if(midval < target)
                r = mid-1;
            else
                l = mid+1;
        }
        return -1;
    }
};