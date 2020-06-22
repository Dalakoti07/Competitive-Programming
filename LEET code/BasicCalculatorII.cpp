class Solution {
public:
    bool isGreater1GreatThan2(char op1,char op2 ){
        if(op1=='*' or op1=='/'){
            return true;
        }
        if(op1=='-' or op1=='+'){
            if(op2=='*' or op2=='/') return false;
            return true;
        }
    }

    int calculate(string s) {
        int n =s.length();
        int i=0;
        if(s[0]==' ')
            i++;
        // find operand
        int operand;
        char operator;
        for(int j=i;j<n and isOperator(s[j]);j++)
            
    }
};