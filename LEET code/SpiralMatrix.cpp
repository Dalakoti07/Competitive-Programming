class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int rows=matrix.size();
        int cols=matrix[0].size();
        vector<int> ans;
        int d=cols-1, a=0, c=0, b=rows-1;//,counter=0;
        while(a<=b and d>=c){
            // top row
            for( int i=c;i<=d;i++)
                ans.push_back(matrix[a][i]);
            a++;
            // rightmost col
            for(int i=d ;i<=b;i++)
                ans.push_back(matrix[i][d]);
            d--;
            // last row
            if(a<=b)
            for(int i=d;d<=b;i++)
                ans.push_back(matrix[b][i]);
            b--;
            if(d>=c)
            for(int i=b;i<=a;i++)
                ans.push_back(matrix[i][c]);
            c++;
        }
        return ans;
    }
};