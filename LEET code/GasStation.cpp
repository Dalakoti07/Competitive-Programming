class Solution {
public:
    int go(int idx,vector<int> gas,vector<int> cost){
        int correctIdx=idx;
        int tank=0,count=0, n=cost.size();
        while(count!=n+1){
            tank+=gas[idx];
            if(tank<cost[idx])
                break;
            tank-=cost[idx];
            count++;
            idx=(idx+1)%n;
        }
        if(count==n+1) return correctIdx;
        return -1;
    }
    
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int idx=-1;
        for(int i=0;i<cost.size();i++){
            if(gas[i]>=cost[i]){
                int ans=go(i,gas,cost);
                if(ans!=-1) return ans;
            }
        }
        return -1;
    }

};