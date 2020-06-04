class Solution {
public:
    // brute force find all pair(i,j) such that arr[i]-arr[j] is great, and arr[i]<arr[j], O n square complexity
    /*int maxProfit(vector<int>& prices) {
        int maximum=INT_MIN;
        for(int i=0;i<prices.size();i++){
            for(int j=i+1;j<prices.size();j++){
                if(prices[i]<prices[j] and prices[j]-prices[i]>maximum){
                    maximum=prices[j]-prices[i];
                }
            }
        }
        if(maximum==INT_MIN){
            maximum=0;
        }
        return maximum;
    }*/

    int maxProfit(vector<int>& prices) {
        int maximumProfit=0,minPoint=INT_MAX;
        for(int i=0;i<prices.size();i++){
            if(prices[i]<minPoint){
                minPoint=prices[i];
            }else if(prices[i]-minPoint>maximumProfit){
                maximumProfit= prices[i]-minPoint;
            }
        }
        return maximumProfit;
    }
};