class Solution {
public:
    int minSetSize(vector<int>& arr) {
        // greedy take max occuring element first
        unordered_map<int,int> mappy;
        int n = arr.size();
        
        for(int i=0;i<n;i++){
            if(mappy.count(arr[i]==0))
                mappy[arr[i]]=1;
            else mappy[arr[i]]+=1;
        }

        int midSize =n/2,count=0;
        vector<pair<int,int>> vecy;
        // convert map to vector
        for(auto iter:mappy){
            vecy.push_back(make_pair(iter.first,iter.second));
        }
        sort(vecy.begin(),vecy.end(),[](pair<int,int>& a,pair<int,int>& b){
            return a.second > b.second;
        });

        for(auto iter: vecy){
            n-=iter.second;
            count++;
            if(n<=midSize){
                break;
            }
        }
        return count;
    }
};