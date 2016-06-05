class Solution {
public:
    double myPow(double x, int n) {
        if (n < 0) return 1 / (x*myPow(x, -(++n)));
        else if (n == 0) return 1;
        else return (n % 2 == 0) ? myPow(x*x, n / 2) : x*myPow(x*x, n / 2);;
    }
};
