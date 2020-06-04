class Solution {
public:
    int nthUglyNumber(int n) {
        // most of numbers are not ugly, instead of checking ugly ,generate them
        set<int> uglyNumbers{1,2,3,4,5};

        // generating ugly numbers
        for(int i=2;i<=564;i++){
            uglyNumbers.insert(3*i);
            uglyNumbers.insert(2*i);
            uglyNumbers.insert(5*i);
        }
        set<int>::iterator iter = uglyNumbers.begin();
        
        // It will move forward the passed iterator by passed value
        advance(iter, n-1);
        return *iter;
    }
};