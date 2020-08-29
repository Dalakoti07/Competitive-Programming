class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        // the problem is reduced to increase grid[i][j] such that max in row[i] and col[j] does not change
        // so grid[i][j] would be changed to min(maxRow[i],maxCol[j])

        int n=grid.size(),m = n? grid[0].size() : 0;
        if(n*m == 0) return 0;
        vector<int> rowMax(n);
        vector<int> colMax(m);
        for(int i=0;i<n;i++){
            // max in row i
            int Max=INT_MIN;
            for(int j=0;j<m;j++)
                Max=max(Max,grid[i][j]);
            rowMax[i]=Max;
        }

        for(int i=0;i<m;i++){
            // max in col i
            int Max=INT_MIN;
            for(int j=0;j<n;j++)
                Max=max(Max,grid[j][i]);
            colMax[i]=Max;
        }
        // for(int v: colMax)
        //     cout<<v<<" ";
        // cout<<endl;
        // for(int v: rowMax)
        //     cout<<v<<" ";
        
        int minAddition=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                minAddition+=min(colMax[j],rowMax[i])-grid[i][j];
            }
        }
        return minAddition;
    }
};