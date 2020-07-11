class Solution {
public:
    bool static comparator(vector<int>& a,vector<int>& b){
        if(a[0]==b[0])
            return a[1]<b[1];
        return a[0]<b[0];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        int count =0,end;
        end=intervals[0][1];
        for(int i=1;i<intervals.size();i++){
            if(intervals[i][0]<end){
                count++;
            }else{
                end=intervals[i][1];
            }
        }
        return count;
    }
};