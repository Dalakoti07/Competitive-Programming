class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int rows=matrix.size();
        int cols=matrix[0].size();
        if(rows==0 or cols==0) return vector<int>(0);
        if(rows==1) return vector<int>{matrix[0]};
        vector<int> ans;
        int d=cols-1, a=0, c=0, b=rows-1;//,counter=0;
        while(a<=b and d>=c){
            // top row
            for( int i=c;i<=d;i++)
                ans.push_back(matrix[a][i]);
            a++;
            // rightmost col
            for(int i=a ;i<=b;i++)
                ans.push_back(matrix[i][d]);
            d--;
            // last row
            if(d>=c)
            for(int i=d;i>=c;i--)
                ans.push_back(matrix[b][i]);
            b--;
            if(b>=a)
            for(int i=b;i>=a;i--)
                ans.push_back(matrix[i][c]);
            c++;
        }
        return ans;
    }
};