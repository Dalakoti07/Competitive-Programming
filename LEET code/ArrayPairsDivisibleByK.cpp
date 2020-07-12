class Solution {
public:
    bool ifAllAreDone(vector<int>& arr){
        for(int i:arr){
            if(i!=INT_MAX){
                cout<<" i : "<<i;
                return false;
            }
        }
        return true;
    }

    bool canArrange(vector<int>& arr, int k) {
        vector<int> arrModK=arr;
        for(int i=0;i<arrModK.size();i++)
            arrModK[i]=arrModK[i]%k;
        // find the pairs
        int bound =arrModK.size(),temp;
        for(int i=0;i<bound;i++){
            if(arr[i]!=INT_MAX){
                temp=arr[i];
                arr[i]=INT_MAX;
                if(find(arrModK.begin(),arrModK.end(),k-arrModK[i])!=arrModK.end()){
                    arrModK[i]=INT_MAX;
                }else{
                    arr[i]=temp;
                }
            }
        }
        return ifAllAreDone(arr);
    }
};