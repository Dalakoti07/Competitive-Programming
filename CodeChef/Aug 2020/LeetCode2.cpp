class Solution {
public:
    bool canConvertString(string s, string t, int k) {
        if(s.length()!=t.length()) return false;
        int diffs;
        set<int> movesDone;
        for(int i=0;i<s.length();i++){
            diffs=t[i]-s[i];
            if(diffs<0){
                diffs=26-abs(diffs);
            }
            if(diffs!=0){
                if(diffs>k)
                    return false;
                if(movesDone.find(diffs)==movesDone.end()){
                    movesDone.insert(diffs);
                }else{
                    // check 26 multiples
                    bool found=false;
                    for(int i=1;i<=(int)(1e9)/26;i++){
                        if((i*26)+diffs >k)
                            break;
                        else{
                            if(movesDone.find((i*26)+diffs)==movesDone.end()){
                                found=true;
                                movesDone.insert((i*26)+diffs);
                                break;
                            }
                        }
                    }
                    if(!found)
                        return false;
                }
            }
        }
        // make decisions
        return true;
    }
};