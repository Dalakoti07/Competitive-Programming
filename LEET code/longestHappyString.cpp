class Solution {
public:
    void addCharsToString(string& str,char c,int count){
        for(int i=0;i<count;i++)
            str+=c;
    }

    char tellCharacterToBeAdded(int a,int b,int c,char lastUsed='x'){
        if(lastUsed=='a')
            a=-1;
        else if(lastUsed=='b')
            b=-1;
        else if(lastUsed=='c')
            c=-1;

        if(a>=b and a>=c)
            return 'a';
        else if(b>=a and b>=c)
            return 'b';
        else
            return 'c';
    }

    string longestDiverseString(int a, int b, int c) {
        string ans="";
        char lastUsed='x';
        while(a>0 or b>0 or c>0){
            char c=tellCharacterToBeAdded(a,b,c,lastUsed);
            if(c=='c'){
                addCharsToString(ans,'c',min(c,2));
                c-=min(c,2);   
            }else if(c=='a'){
                addCharsToString(ans,'a',min(a,2))
                a-=min(a,2);
            }else if(b>c and b>a){
                addCharsToString(ans,'b',min(b,2));
                b-=min(b,2);
            }
        }
        return ans;
    }
};