// https://www.hackerrank.com/contests/interview-for-geeks-contest-1/challenges/naman-dont-like-palindrome/problem
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    string s;
    bool changed=false;
    cin>>s;
    int n= s.length();
    for(int i=0,j=n-1;i<j;){
        if(s[i]!='a'){
            s[i]='a';
            changed=true;break;
        }
        i++;
        j--;
    }
    if(changed) cout<<s;
    else{
        cout<<"IMPOSSIBLE";
    }
    return 0;
}
