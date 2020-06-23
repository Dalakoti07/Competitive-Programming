class Solution {
public:
    int minCostToMoveChips(vector<int>& chips) {
        // its optimal to move all the chips toward median, and later I figured out it was wrong, eg 2,3,3
        // moving all scattered chips toward center is far better than moving them toward left ot right extreme

        /*Since moving chips by 2 items costs 0, we can stack all chips with 0 cost in first two positions. On position 0 (since we talk about array) will go all chips that are initially located on even positions and on position 1 will be all chips that are initially on odd posititions. Finally we need to take smallest stack and move chip one by one with cost of 1.

        The whole problem can be simplified to "On which posititions we have more chips: odd or even"?
        To solve this we can count all odd positioned chips (position & 1 == 1), even positioned chips count = all chips - odd positioned. We take smallest of two numbers.
        */
        int even=0,odd=0;
        for(int i=0;i<chips.size();i++){
            if(chips[i]%2==0) even++;
            else odd++;
        }
        return min(odd,even);
    }
};