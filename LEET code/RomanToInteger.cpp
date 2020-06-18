class Solution {
public:
    int romanToInt(string s) {
        int n =s.length();
        if(n==0) return 0;
        int val;
        if(n==1){
            if(s[0]=='I') return 1;
            if(s[0]=='V') return 5;
            if(s[0]=='X') return 10;
            if(s[0]=='L') return 50;
            if(s[0]=='C') return 100;
            if(s[0]=='D') return 500;
            if(s[0]=='M') return 1000;
        }else{
            bool twoChar=false;
            if(s[0]=='I'){
                if(s[1]=='V'){
                    twoChar=true;
                    val=4;
                }else if(s[1]=='X'){
                    twoChar=true;
                    val=9;
                }else{
                    val=1;
                }
            }
            else if(s[0]=='V'){
                val=5;
            }
            else if(s[0]=='X'){
                if(s[1]=='L'){
                    twoChar=true;
                    val=40;
                }else if(s[1]=='C'){
                    twoChar=true;
                    val=90;
                }else{
                    val=10;
                }
            }
            else if(s[0]=='L'){
                val=50;
            }
            else if(s[0]=='C'){
                if(s[1]=='D'){
                    twoChar=true;
                    val=400;
                }else if(s[1]=='M'){
                    twoChar=true;
                    val=900;
                }else{
                    val=100;
                }
            }
            else if(s[0]=='D'){
                val=500;
            }
            else if(s[0]=='M'){
                val=1000;
            }
            if(twoChar){
                val+= romanToInt(s.substr(2));
            }else{
                val+=romanToInt(s.substr(1));
            }
        }
        return val;
    }
};