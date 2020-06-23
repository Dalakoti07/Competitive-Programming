class Solution {
public:
    static bool comp(pair<int,int>& a,pair<int,int>& b ){
        return a.first < b.first;
    }

    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        // greedy approach is that we are clubbing the people together and then group them  together
        vector<vector<int>> ans;

        if(groupSizes.size()==0) return ans;
        if(groupSizes.size()==1){
            ans.push_back(vector<int>{0});
            return ans;
        } 

        vector<pair<int,int>> sortedGroupWithIndex;
        for(int i=0;i<groupSizes.size();i++){
            sortedGroupWithIndex.push_back(make_pair(groupSizes[i],i));
        }
        sort(sortedGroupWithIndex.begin(),sortedGroupWithIndex.end(),comp);
        
        int n =sortedGroupWithIndex.size();
        for(int i=0;i<n;){
            int people =1,eachGroupSize=sortedGroupWithIndex[i].first,start=i;
            i+=1;
            while(i<n and sortedGroupWithIndex[i].first==eachGroupSize ){
                i+=1;people++;
            }
            int noOfGroups=people/eachGroupSize;
            for(int group=0;group<noOfGroups;group++){
                // copy vec from start to start+each_groupSize, then from there to next each_group_size
                vector<int> tempo(eachGroupSize);
                for(int i=0;i<eachGroupSize;i++)
                    tempo[i]=sortedGroupWithIndex[start++].second;
                ans.push_back(tempo);
            }
        }
        return ans;
    }
};