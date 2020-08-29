class Solution {
public:
    static bool compareInterval(pair<int,int> i1, pair<int,int> i2) {
        return (i1.second < i2.second); 
    } 
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        map<int,int> keyVal;
        for(int i=0;i<arr.size();i++)
            keyVal[arr[i]]++;
        vector<pair<int,int>> vecMap;
        for(auto &a: keyVal){
            vecMap.push_back(a);
        }
        sort(vecMap.begin(),vecMap.end(),compareInterval);

        int i=0,j=0;
        for(;j<vecMap.size();j++){
            if(vecMap[j].second<=k){
                k-=vecMap[j].second;
                if(k==0){
                    j++;
                    break;                    
                }
            }else{
                break;                
            }
            // cout<<"after j: "<<j<<" we have k: "<<k<<endl;
        }
        return vecMap.size()-j;
    }
};