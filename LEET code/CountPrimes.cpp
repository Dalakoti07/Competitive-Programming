class Solution {
public:
    bool isPrime(int number){
        for(int i=2;i<=sqrt(number);i++){
            if(number%i ==0) return false;
        }
        return true;
    }

    int countPrimes(int n) {
        if(n<=1) return 0;
        if(n==2) return 0;
        int count =1;
        for(int i=3;i<n;i=i+2){
            if(isPrime(i))
                count++;
        }
        return count;
    }
};