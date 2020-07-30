/**
 * // This is the ArrayReader's API interface.
 * // You should not implement it, or speculate about its implementation
 * class ArrayReader {
 *   public:
 *     // Compares the sum of arr[l..r] with the sum of arr[x..y] 
 *     // return 1 if sum(arr[l..r]) > sum(arr[x..y])
 *     // return 0 if sum(arr[l..r]) == sum(arr[x..y])
 *     // return -1 if sum(arr[l..r]) < sum(arr[x..y])
 *     int compareSub(int l, int r, int x, int y);
 *
 *     // Returns the length of the array
 *     int length();
 * };
 */

class Solution {
public:
    int getIndex(ArrayReader &reader) {
        int n = reader.length(), l = 0, r = n-1, midl, midr;
        int flag;
        while(l < r)
        {
        	if((r-l)&1)//差为奇数
        		midl = (l+r)/2,
        		midr = (l+r)/2+1;
        	else//偶数
        		midl = midr = (l+r)/2;
        	flag = reader.compareSub(l, midl, midr,r);
        	if(flag > 0)//左边和大
        		r = midl;
        	else if(flag < 0)//右边和大
        		l = midr;
        	else//相等找到了
        		return midl;
        }
        return l;
    }
};