#include <bits/stdc++.h>
using namespace std;
// https://www.geeksforgeeks.org/longest-palindromic-substring-set-2/ for better O(1) space
void solve(string s){
    int n=s.length();
    bool arr[n][n];
    memset(arr,0,sizeof(arr));
    int start=0,length=1;
    // filling the dp array in diagonal way

    // setting all the palindromes of size 1 as valid palindrome 
    for(int i=0;i<n;i++){
        arr[i][i]=true;
    }
    // setting strings of size 2 
    for(int i=0;i<n-1;i++)
        if(s[i]==s[i+1]){
            arr[i][i+1]=true;
            if(length==1){
                start=i;
                length=2;                
            }
        }
    // other strings of length k
    for(int k=3;k<=n;k++){
        for(int i=0;i<n-k+1;i++){
            // j is end 
            int j=i+k-1;
            if(arr[i+1][j-1] and (s[i]==s[j])){
                arr[i][j]=true;
                if(k>length){
                    start=i;
                    length=k;
                }
            }
        }
    }
    
    // print the string 
    for(int i=start;i<start+length;i++)
        cout<<s[i];
    cout<<endl;
}

int main() {
    int t;
    cin>>t;
    while(t--){
        // its a typical DP problem
        string s;
        cin>>s;
        solve(s);
    }
	return 0;
}