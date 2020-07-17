/**
 * The read4 API is defined in the parent class Reader4.
 *     int read4(char *buf);
 */

class Solution {
	queue<char> q;//一次读取4个，可能多了，存储起来
public:
    /**
     * @param buf Destination buffer
     * @param n   Number of characters to read
     * @return    The number of actual characters read
     */
    int read(char *buf, int n) {
        if(!buf || n <= 0)
        	return 0;
        int len = 0, total = 0;
        int offset = 0;
        while(!q.empty())//临时存储区还有先用掉
        {
        	buf[offset++] = q.front();
        	q.pop();
            total++;
        	if(offset == n)//个数到了
        		return n;
        }
       	do
        {
        	len = read4(buf+offset);//读取了len个有效字符，写入offset位置
        	total += len;
        	offset += len;
        }while(len==4 && len < n);

        if(total > n)
        {	//读取多了，存到临时存储区
        	for(int i = n; i < total; i++)
		    	q.push(buf[i]);
        }        
        return min(n,total);
    }
};