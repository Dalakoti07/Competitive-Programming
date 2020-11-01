class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        // approach greedy if we can move in x and y both then move diagonally
        int count=0,dx=0,dy=0;
        bool upHill=false;
        for(int i=1;i<points.size();){
            if(dx==0 and dy==0){
                dx=points[i][0]-points[i-1][0];
                dy=points[i][1]-points[i-1][1];
                if(dx>=0 and dy>=0)
                    upHill=true;
                else
                    upHill=false;
            }

            if((dx>0 and dy>0) or (dx<0 and dy<0)){
                count+=min(dx,dy);
                if(upHill){
                    dx-=min(dx,dy);
                    dy-=min(dx,dy);
                }else{
                    dx+=min(dx,dy);
                    dy+=min(dx,dy);
                }
            }else if(dx>0 or dx<0){
                count++;
                if(upHill)
                    dx--;
                else
                    dx++;
            }else{
                count++;
                if(upHill)
                    dy--;
                else
                    dy++;
            }
            if(dx==0 and dy==0)
                i++;
        }
        return count;
    }
};