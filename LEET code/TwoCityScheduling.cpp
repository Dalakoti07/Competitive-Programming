class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        
        /*
        it turns out to be a wrong approach do with dp
        // greedy approach, n/2 min of city A are picked and remaining cost of city B is added to answer
        // or vice versa of above, which means n/2 min of city B are picked and remaining cost of city A is added to answer

        // for greedy refer below
        // greedy solution (Tough One)
        static bool com(int a,int b){
            return a>b;
        }
        int twoCitySchedCost(vector<vector<int>>& costs) {
            int ans(0);
            vector<int>refund;
            for(auto it:costs){
                ans+=it[0];
                refund.push_back(it[0]-it[1]);
            }
            sort(begin(refund),end(refund),com);
            for(int i=0;i<(refund.size()/2);i++)ans-=refund[i];
            return ans;
        }
        */
        // solve with recursion and then dp

        return ;
    }
};