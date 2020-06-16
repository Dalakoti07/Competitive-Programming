class Solution {
public:
//   TLE in 1/7
    string fractionToDecimal(int divident, int divisor) {
        string fractionalAnswer="";
        int integralPart=divident/divisor;
        string integralPartString =to_string(integralPart);
        int remainder=divident%divisor;
        if (remainder==0) 
            return integralPartString;
        integralPartString+=".";
        divident=remainder*10;
        while(1){
            remainder=divident%divisor;
            int quotient =divident/divisor;
            if(remainder==0){
                fractionalAnswer+=to_string(quotient);
                break;
            }else if(remainder == divident/10){
                fractionalAnswer+="("+to_string(quotient)+")";
                break;
            }else{
                fractionalAnswer+=to_string(quotient);
            }
            divident=remainder*10;
        }
        return integralPartString+fractionalAnswer;
    }
};