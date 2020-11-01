class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        if(candies.size()==0)
            return vector<bool>();
        int max=*max_element(candies.begin(),candies.end());
        vector<bool> isPossible;
        for(int each: candies){
            if(each+extraCandies>=max)
                isPossible.push_back(true);
            else
                isPossible.push_back(false);
        }
        return isPossible;
    }
};