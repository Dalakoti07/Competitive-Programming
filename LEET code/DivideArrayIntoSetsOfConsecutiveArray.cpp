class Solution {
public:
    // see other approaches
    // it could have been done with priority queue
    bool isPossibleDivide(vector<int>& nums, int k) {
        multiset<int> setsOfAll(nums.begin(),nums.end());
        while(setsOfAll.size()!=0){
            int i=1;
            int start=*(setsOfAll.begin());
            setsOfAll.erase(setsOfAll.begin());
            while(i!=k){
                int next=start+1;
                auto itr= setsOfAll.find(next);
                if(itr==setsOfAll.end())
                    return false;
                start=next;
                setsOfAll.erase(itr);
                i++;
            }
        }
        return true;
    }
};