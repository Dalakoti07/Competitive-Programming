class Solution {
public:
    // https://leetcode.com/problems/car-pooling/discuss/488607/c%2B%2B-two-solutions-clean-and-simple

    bool carPooling(vector<vector<int>>& trips, int capacity) {
        // beautiful solution from discussion
        // record all the passengers at every point of time
        vector<int> allTrips=vector<int>(1001,0);
        for(auto v:trips){
            allTrips[v[1]]+=v[0];
            allTrips[v[2]]-=v[0];
        }

        // check if at any point of time passenger count crossed maxLimit
        int count =0;
        for(int i=1;i<=1000;i++){
            count+=allTrips[i];
            if(count>capacity) return false;
        }
        return true;
    }
};