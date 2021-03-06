class Solution {
public:
    bool isPowerOfThree(int n) {
	    if (n <= 0)
		    return false;
	    double value = log10(n) / log10(3);
	    return ceil(value) == floor(value);
    }
};