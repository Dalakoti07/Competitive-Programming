#include <bits/stdc++.h> 
using namespace std; 
const int MAX_CHAR = 256; 
  
// Returns count of distinct sunsequences of str. 
int countSub(string str) 
{ 
    // Create an array to store index 
    // of last 
    vector<long long> last(MAX_CHAR, -1); 
  
    // Length of input string 
    int n = str.length(); 
  
    // dp[i] is going to store count of distinct 
    // subsequences of length i. 
    long long dp[n+1]; 
  long long temp;
    // Empty substring has only one subsequence 
    dp[0] = 1; 
  
    // Traverse through all lengths from 1 to n. 
    for (int i=1; i<=n; i++) 
    { 
        // Number of subsequences with substring 
        // str[0..i-1] 
        temp=(2l*dp[i-1]);
        dp[i] = temp%(int(1e9)+7); 
        //cout<<"dp[i] at 29 "<<dp[i]<<endl;
  
        // If current character has appeared 
        // before, then remove all subsequences 
        // ending with previous occurrence. 
        if (last[str[i-1]] != -1) 
            dp[i] = (dp[i] - dp[last[str[i-1]]]+int(1e9)+7)%(int(1e9)+7); 
          //cout<<"dp[last] "<<dp[last[str[i-1]]]<<" dp[i] at 36 "<<dp[i]<<endl;

        // Mark occurrence of current character 
        last[str[i-1]] = (i-1); 
    } 
  
    return dp[n]; 
} 
  
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        cout<<countSub(s)<<endl;
    }
    return 0; 
} 