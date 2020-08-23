class Solution {
public:
    // we will do use the memo
    int memo[20][20];
    // memo[i][j] means bst's possible if we take nodes value as i...j
    int count=0;
    int numTrees(int n) {
        memset(memo,-1,sizeof(memo));
        if(n<=2) return n;
        for(int i=1;i<=n;i++){
            // if each node i is made tree than what would be count of such trees
            int recAns;
            if(i==1){
                recAns=1*(memo[i+1][n]= treeWithRange(i+1,n));
            }
            else if(i==n){
                recAns=(memo[1][i-1]= treeWithRange(1,i-1))*1;
            }
            else
                recAns= (memo[1][i-1]= treeWithRange(1,i-1))*(memo[i+1][n]=treeWithRange(i+1,n));
            count+=recAns;
        }
        return count;
    }

    int treeWithRange(int start,int end){
        if(start==end) return 1;
        if(memo[start][end]!=-1) return memo[start][end];
        int lcount=0;
        for(int i=start;i<=end;i++){
            int recAns;
            if(i==start)
                recAns=1*(treeWithRange(i+1,end));//memo[i+1][end]= 
            else if(i==end)
                recAns=(treeWithRange(start,i-1))*1;//memo[start][i-1] =
            else
                recAns=(treeWithRange(start,i-1))*(treeWithRange(i+1,end));//memo[start][i-1]= , memo[i+1][end]= 
            // cout<<"\nnested call --> tree with root as "<<i<<" is "<<recAns<<endl;
            lcount+=recAns;
        }
        memo[start][end]=lcount;
        return lcount;
    }
};

