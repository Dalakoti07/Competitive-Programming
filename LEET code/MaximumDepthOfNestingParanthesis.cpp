class Solution {
public:
    /*
        1.         ( ( ( ( ( ) ) ) ) )
        level   1 2 3 4 5 5 4 3 2 1  
        A takes level 1,3,5 and B takes level 2,4 ==> A : ( ( ( ) ) ) , B : ( ( ) )
        2.         ( ( ) ) ( ( ( ) ) )
        level   1 2 2 1 1 2 3 3 2 1
        A takes level 1,3 and B takes level 2 ==> A : ( ) ( ( ) ) , B : ( ) ( )
        
        when to increase/decrese level ?
        1. meet a new '(' level up
        2. meet a new ')' level down
    */
    // since we want minimum length, thus we would divide the depth to equal portion between A and B, as shown in above example
    // we would toggle between A and B.
    vector<int> maxDepthAfterSplit(string seq) {
        vector<int> ans (seq.length(),0);
        int n =seq.length(),idx=0;
        for(int i=0;i<n;i++){
            if(seq[i]=='('){
                ans[i]=idx++ % 2 ;
            }else ans[i]= --idx % 2;
        }
        return ans;
    }
};