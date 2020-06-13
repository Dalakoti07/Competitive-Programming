class Solution {
private:
    double power(double x, long long y) {
        long long k = y;
        y = abs(y);
        double result = 1;
        while (y) {
            if (y & 1) 
                result = k >= 0 ? result * x : result / x;
            x = x * x;
            y >>= 1;
        }
        return result;
    }
    
public:
    double myPow(double x, int n) {
        return power(x, n);
    }
};