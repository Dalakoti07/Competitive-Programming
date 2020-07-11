class Solution {
public:
    // see other approaches
    // it could have been done with priority queue
    bool isPossibleDivide(vector<int>& nums, int k) {
        multiset<int> setsOfAll;
        for(auto i:nums)
            setsOfAll.insert(i);
        
        while(setsOfAll.size()!=0){
            int i=1;
            int start=*(setsOfAll.begin());
            setsOfAll.erase(setsOfAll.begin());
            while(i!=k){
                if(setsOfAll.size()==0) return false;
                int next=*(setsOfAll.begin());
                if(next!=start+1)
                    return false;
                else
                    start=next;
                i++;
            }
        }
        return true;
    }
};