class Solution {
public:
    static bool comparator(pair<int,int>& p1,pair<int,int>& p2){
        return p1.first > p2.first;
    }

    int largestValsFromLabels(vector<int>& values, vector<int>& labels, int num_wanted, int use_limit) {
        // simple greedy using and taking large elements
        vector<pair<int,int>> combo= vector<pair<int,int>>();
        for(int i=0;i<values.size();i++){
            combo.push_back(make_pair(values[i],labels[i]));
        }
        // sort
        sort(begin(combo),end(combo),comparator);
        int i=0,k=0;
        unordered_map<int,int> labelsAndCount;
        int maxCount=0;
        while(k<num_wanted and i<combo.size()){
            if(labelsAndCount.count(combo[i].second)!=0 and labelsAndCount[combo[i].second]==use_limit){
                i++;
                continue;
            }
            maxCount+=combo[i].first;
            if(labelsAndCount.count(combo[i].second)==0)
                labelsAndCount[combo[i].second]=1;
            else
                labelsAndCount[combo[i].second]+=1;
            i++;
            k++;
        }
        return maxCount;
    }
};