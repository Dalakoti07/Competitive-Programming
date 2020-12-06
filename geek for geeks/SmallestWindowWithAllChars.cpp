#include <bits/stdc++.h>
using namespace std;

int solve(string str){
    int n = str.length(),uniques=0; 
    const int TOTAL=255;
    int hash[TOTAL]={0};
    for(int i=0;i<n;i++){
        if(hash[str[i]]==0){
            uniques++;
            hash[str[i]]++;
        }
    }
    string ans="";
    // now find the smallest window using sliding window 
    int start=0,start_idx=0,minLen=INT_MAX; 
    int count=0;//uniqueInCurrWindow
    int currCount[TOTAL]={0};
    for(int j=0;j<n;j++){
        currCount[str[j]]++;
        if(currCount[str[j]]==1){
            count++;
        }
        if(count==uniques){
            // try to trim the string from front ,this is the optimization
            while(currCount[str[start]]>1){
                currCount[str[start]]--;
                start++;
            }
            // update window size
            int len_window = j - start + 1; 
            if (minLen > len_window) { 
                minLen = len_window; 
                start_idx = start; 
            }
        }
    }
    return str.substr(start_idx, minLen).size(); 
}

int main() {
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        cout<<solve(s)<<endl;
    }
	return 0;
}