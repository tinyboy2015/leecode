class Solution {
public:
	int divide(int dividend, int divisor) {
		if(divisor==0){
			return dividend>=0?INT_MAX:INT_MIN;
		}
		if(dividend==0){
			return 0;
		}
		if(dividend==INT_MIN&&divisor==-1){
			return INT_MAX;
		}
		bool isNegative=(dividend<0&&divisor>0)||(dividend>0&&divisor<0);
		long a=abs(dividend);
		long b=abs(divisor);
		int result=0;
		while (a>=b){
			int shift=0;
			while(a>=(b<<shift)){
				shift++;
			}
			a-=b<<(shift-1);
			result+=1<<(shift-1);
		}
		return isNegative?-result:result;
	}
};

class Solution {
public:
    int divide(int dividend, int divisor) {
        if (!divisor || (dividend == INT_MIN && divisor == -1))
            return INT_MAX;
        int sign = ((dividend < 0) ^ (divisor < 0)) ? -1 : 1;
        long long dvd = labs(dividend);
        long long dvs = labs(divisor);
        int res = 0;
        while (dvd >= dvs) { 
            long long temp = dvs, multiple = 1;
            while (dvd >= (temp << 1)) {
                temp <<= 1;
                multiple <<= 1;
            }
            dvd -= temp;
            res += multiple;
        }
        return sign == 1 ? res : -res; 
    }
};