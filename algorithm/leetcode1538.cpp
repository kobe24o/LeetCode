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
public:
    int guessMajority(ArrayReader &reader) {
        int n = reader.length();
        int start = reader.query(0,1,2,3);
        int g1 = 1, g2 = 0, idx1 = 0, idx2 = -1;

        for(int i = 4; i < n; ++i)
        {
            if(reader.query(1,2,3,i)==start)
                g1++;
            else
                g2++, idx2 = i;
        }//0,4,5...n-1 都确定了是否是一类
        //还要确定1,2,3
        int q = reader.query(0,2,3,4);
        int p = reader.query(1,2,3,4);
        if(q == p)//0和1是一类
            g1++;
        else
            g2++, idx2 = 1;
        q = reader.query(0,1,3,4);
        // p = reader.query(1,2,3,4);
        if(q == p)//0和2是否是一类
            g1++;
        else
            g2++,idx2 = 2;
        q = reader.query(0,1,2,4);
        // p = reader.query(1,2,3,4);
        if(q == p)//0和3是否是一类
            g1++;
        else
            g2++,idx2 = 3;
        if(g1 == g2) return -1;
        if(g1 > g2) return idx1;
        return idx2;
    }
};