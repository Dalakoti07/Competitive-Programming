class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        // we want to serve as many people, though its not given here
        // the greddy here is that we will use big coins first and if they are vanished then we will use small coins
        // as by doing so we can serve more people as many small can produce big changes if required, but if small changes 
        // are used early than, if at some point we want these small changes to run shop, if we will stuck
        int fiveRupeeChange=0,tenRupeeChange=0;
        int n = bills.size();
        for(int i=0;i<n;i++){
            if(bills[i]==5){
                fiveRupeeChange+=1;
            }else if(bills[i]==10){
                tenRupeeChange+=1;
                if(fiveRupeeChange>0) fiveRupeeChange--;
                else return false;
            }else{
                if(tenRupeeChange>0 and fiveRupeeChange>0){
                    tenRupeeChange-=1;
                    fiveRupeeChange-=1;
                }else if(fiveRupeeChange>2) fiveRupeeChange-=3;
                else return false;
            }
        }
        return true;
    }
};