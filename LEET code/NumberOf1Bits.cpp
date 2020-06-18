class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count=0;
        uint32_t one =1;
        while(n!=0){
            if(n&one ==one){
                count++;
            }
            n>>1;
        }
        return count;
    }
};