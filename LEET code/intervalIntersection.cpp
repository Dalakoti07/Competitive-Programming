class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
        int i=0,j=0,n=A.size(),m=B.size();
        vector<vector<int>> ans;
        if(n*m == 0) return ans;
        int AStart=A[0][0],AEnd=A[0][1],BStart=B[0][0],BEnd=B[0][1];
        for(;i<n;){
            for(;j<m;){
                cout<<"i: "<<i<<" j: "<<j<<" a:("<<AStart<<","<<AEnd<<") and b:("<<BStart<<","<<BEnd<<") ";
                if(BEnd<AStart){
                    // B array is behind
                    cout<<"b is behind \n";
                    j++;
                    if(j==m)
                        break;
                    BStart=B[j][0];
                    BEnd=B[j][1];
                }if(AEnd<BStart){
                    cout<<"a is behind \n";
                    // A is behind
                    i++;
                    if(i==n)
                        break;
                    AStart=A[i][0];
                    AEnd=A[i][1];
                }
                else{// chance of overlap
                    if(BEnd>=AStart and BStart<AStart){// prefix overlap
                        cout<<"prefix overlap \n";
                        int olStart=max(AStart,BStart);
                        int olEnd=min(AEnd,BEnd);
                        ans.push_back(vector<int>{olStart,olEnd});
                        j++;
                        if(j==m)
                        break;
                        BStart=B[j][0];
                        BEnd=B[j][1];
                    }else if(BStart>=AStart and BEnd<=AEnd){//overlap inside
                        cout<<"inside overlap \n";
                        ans.push_back(vector<int>{BStart,BEnd});
                        j++;
                        if(j==m)
                        break;
                        BStart=B[j][0];
                        BEnd=B[j][1];
                    }else if(BStart<=AEnd and BEnd>AEnd){//overlap suffix
                        cout<<"suffix overlap \n";
                        ans.push_back(vector<int>{BStart,AEnd});
                        j++;
                        if(j==m)
                        break;
                        BStart=B[j][0];
                        BEnd=B[j][1];                        
                    }
                }
            }
            if(j==m)
                break;
        }
        return ans;
    }
};