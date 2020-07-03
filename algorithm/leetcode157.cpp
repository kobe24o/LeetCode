/**
 * The read4 API is defined in the parent class Reader4.
 *     int read4(char *buf);
 */

class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Number of characters to read
     * @return    The number of actual characters read
     */
    int read(char *buf, int n) {
        if(!buf || n <= 0)
        	return 0;
        int count = 0, len = 0;
        do
        {
        	len = read4(buf+count);
        	count += len;
        }while(len==4 && count < n);

        if(count > n)
        {
        	buf[n] = '\0';
        	count = n;
        }
        return count;
    }
};