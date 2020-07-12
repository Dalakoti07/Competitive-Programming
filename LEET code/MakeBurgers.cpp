class Solution {
public:
    // beautiful explanation
    // https://leetcode.com/problems/number-of-burgers-with-no-waste-of-ingredients/discuss/441434/Easy-java-to-understand-beats-100    
    vector<int> numOfBurgers(int ts, int cs) {
        if (ts%2==1 || ts/2<cs || ts/4>cs) return {};
        return {ts/2-cs, 2*cs-ts/2};
    }
};