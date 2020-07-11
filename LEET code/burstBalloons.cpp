class Solution {
static bool comparator(vector<int>& a,vector<int>& b){
    return a[0]<b[0];
}

public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if(points.size()==0) return 0;
        sort(points.begin(),points.end(),comparator);
        int i=1,count=1;
        int end=points[0][1];
        for(;i<points.size();){
            if(points[i][0]<=end);
            else{
                count++;
            }
            if(i%2){
                end=-1;
            }else
                end=points[i][1];
            i++;
        }
        return count;
    }
};