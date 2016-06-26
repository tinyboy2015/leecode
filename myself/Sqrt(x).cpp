class Solution1 {
public:
	int mySqrt(int x) {
		if(x==0) return 0;
		long left=1,right=x;
		long middle;
		while(left<right-1){
			middle=(left+right)/2;
			if(middle*middle>x){
				right=middle;
			}else{
				left=middle;
			}
		}
		return left;
	}
};

class Solution {
public:
	int mySqrt(int x) {
		if (x == 0)
			return 0;
		int left = 1, right = INT_MAX;
		while (true) {
			int mid = left + (right - left)/2;
			if (mid > x/mid) {
				right = mid - 1;
			} else {
				if (mid + 1 > x/(mid + 1))
					return mid;
				left = mid + 1;
			}
		}
	}
};