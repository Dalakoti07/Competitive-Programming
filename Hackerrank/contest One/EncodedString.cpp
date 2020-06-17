// https://www.hackerrank.com/contests/interview-for-geeks-contest-1/challenges/encoded-string-2

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void go(vector<long long int>& vec, string code){
    int n =code.length();
    if(n==0) return;
    if(n==1){
        vec[code[0]-'0']+=1;
        return;
    }    
    if(code[1]=='('){
        size_t idx= code.substr(2).find(')');
        // cout<<"chars found for "<<code[0]<<" is :"<<stoi(code.substr(2,idx+1))<<endl;
        vec[code[0]-'0']+=stoi(code.substr(2,idx+1));
        go(vec,code.substr(2+idx));
        return;
    }
    if(code[2]=='#'){
        if(code[3]=='('){
            // find ending paranth for ')'
            size_t idx = code.substr(4).find(')');
            // cout<<"chars found for "<<code.substr(0,2)<<" is :"<<stoi(code.substr(4,idx+1))<<endl;
            vec[(code[0]-'0')*10 + (code[1]-'0')]+= stoi(code.substr(4,idx+1));
            go(vec,code.substr(4+idx));
        }else{
            vec[(code[0]-'0')*10 + (code[1]-'0') ]+=1;
            go(vec,code.substr(3));
        }
        return;
    }
    vec[code[0]-'0']+=1;
    go(vec,code.substr(1));
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    string code;
    cin>>code;
    vector<long long int> wordcount(27,0);
    go(wordcount,code);
    for(int i=1;i<=26;i++){
        // cout<<char('A'+i-1)<<": "<<wordcount[i]<<", ";
        cout<<wordcount[i]<<endl;
    }
    return 0;
}
