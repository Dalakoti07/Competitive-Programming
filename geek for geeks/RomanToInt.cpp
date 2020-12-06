int value(char r){
    if(r=='I')
        return 1;
    if(r=='V')
        return 5;
    if(r=='X')
        return 10;
    if(r=='L')
        return 50;
    if(r=='C')
        return 100;
    if(r=='D')
        return 500;
    if(r=='M')
        return 1000;
    return -1;
}

int romanToDecimal(string &str) {
    int answer=0,n=str.length(),currVal,nextVal;
    for(int i=0;i<n;i++){
        currVal=value(str[i]);
        if(i+1<n){
            nextVal=value(str[i+1]);
            //cout<<"curr :"<<currVal<<" next: "<<nextVal<<endl;
            if(nextVal<=currVal){
                // nothing
            }else{
                currVal=nextVal-currVal;
                i++;
            }
        }
        answer+=currVal;
    }
    return answer;
}