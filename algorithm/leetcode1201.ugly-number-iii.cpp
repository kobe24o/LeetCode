class Solution {
public:
    long nthUglyNumber(long n, long a, long b, long c) {
    	long long mid;
    	long long lcm_ab = lcm(a,b);//ab的最大公约数 
    	long long lcm_ac = lcm(a,c);// ac
    	long long lcm_bc = lcm(b,c);// bc
    	long long lcm_abc = lcm(a,lcm_bc);//abc的最大公约数 
        //一个周期内，abc的最大公约数假设为n，有多少个丑数？
        //是 a 的倍数的 n/a 个 减去重复的 case 4,6,7         case 1
        //是 b 的倍数的 n/b 个 减去重复的 case 4,5,7         case 2
        //是 c 的倍数的 n/c 个  减去重复的 case 5,6,7        case 3
        //是 ab 的倍数的 n/lcm_ab 个 减去重复的 case 7       case 4
        //是 bc 的倍数的 n/lcm_bc 个 减去重复的 case 7       case 5
        //是 ac 的倍数的 n/lcm_ac 个 减去重复的 case 7       case 6
        //是 abc 的倍数的 n/lcm_abc = 1 个                  case 7
        //case1-7汇总：如下
        long long count = lcm_abc/a + lcm_abc/b + lcm_abc/c - lcm_abc/lcm_ab - lcm_abc/lcm_ac - lcm_abc/lcm_bc + 1;
    	long long factor = n/count;//到lcm_abc处有count个丑数，n个丑数还需要几倍
    	long long rest = n%count;//剩余的个数
    	long long ans = factor*lcm_abc;//在factor*lcm_abc处已经得到，还差rest个丑数

    	if(rest > 0)
    	{
    		long long l = 1, r = lcm_abc, mid;
    		while(l < r)
    		{
    			mid = l+((r-l)>>1);
    			count = mid/a + mid/b + mid/c - mid/lcm_ab - mid/lcm_ac - mid/lcm_bc + mid/lcm_abc;
    			if(count >= rest)//mid处可能是答案，不能mid-1
    				r = mid;
    			else// if(count < rest)
    				l = mid+1;
    		}
    		ans += l;
    	}
    	return ans;
    }

    long lcm(long a, long b)//最小公倍数
    {
    	return a*b/gcd(a,b);
    }
    long gcd(long a, long b)//最大公约数
    {
    	long r;
    	while(b)
    	{
    		r = a%b;
    		a = b;
    		b = r;
    	}
    	return a;
    }
};