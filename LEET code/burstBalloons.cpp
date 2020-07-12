class Solution {
static bool comparator(vector<int>& a,vector<int>& b){
    return a[0]<b[0];
}

public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if(points.size()==0) return 0;
        sort(points.begin(),points.end(),comparator);
        int count=0;
        int start=points[0][0],end=points[0][1];
        for(int i=1;i<points.size();i++){
            if(end >=points[i][0]){//overlapping
                start=max(start,points[i][0]);
                end=min(end,points[i][1]);
            }else{
                count++;
                start=points[i][0];
                end=points[i][1];
            }
        }
        count++;
        return count;
    }
};