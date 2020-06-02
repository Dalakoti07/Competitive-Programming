#include<bits/stdc++.h>
using namespace std;

// O( n^3 ) complexity of brute force, will give TLE, but this tle can be avoided using cin tie, but cannot be done in leetcode
// class Solution {
// public:
//     bool checkIfPalindrome(string s,int i,int j){
//         // cout<<"checking ... "<<s.substr(i,j-i+1)<<endl;
//         if(i==j){
//             return true;
//         }
//         for(;i<=j;i++,j--){
//             if (s[i]!=s[j]){
//                 return false;
//             }
//         }
//         return true;
//     }

//     string longestPalindrome(string s) {
//         int longestStringLength =0;
//         string longestString;
//         for(int i=0;i<s.length();i++){
//             if(longestStringLength<1){
//                 longestStringLength=1;
//                 longestString=s.substr(i,1);
//             }
//             for(int j=i;j<s.length();j++){
//                 if(checkIfPalindrome(s,i,j)){
//                    if((j-i+1)>longestStringLength){
//                        longestStringLength=j-i+1;
//                        longestString=s.substr(i,j-i+1);
//                    }
//                 }
//             }
//         }
//         return longestString;
//     }

// };

// another solution is our favourite dp solution, its beautiful, but giving TLE
class Solution {
public:
    string longestPalindrome(string s) {
        // lets make dp array
        // arr[i][j] = {tells if substring between i and j is palindrome or not }
        // recursive equation is arr[i][j] = arr[i+1][j-1] and (s[i]==s[j])
        // Base cases 
        // arr[i][i] =True, and arr[i][i+1] = s[i]==s[i+1]
        int rowCount= s.length();
        bool** arr = new bool*[s.length()];
        for(int i = 0; i < rowCount; ++i)
            arr[i] = new bool[rowCount];
        // fill the base cases
        for(int i=0;i<rowCount;i++){
            for(int j=0;j<rowCount;j++){
                if(i==j)
                    arr[i][j]= true;
                else if(j==i+1)
                    arr[i][j]= s[i]==s[i+1];
                else
                    arr[i][j]=false;
            }
        }

        // fill the matrix diagonally from bottom of table to up
        for(int i = rowCount-3; i>=0; --i){
            for(int j = i+2;j< rowCount; ++j){
                arr[i][j] = (arr[i+1][j-1] && s[i]==s[j]);     
            }
        }

        //find the maxLength and string
        int maxLength=-1;
        string substring;
        for(int i=0;i<rowCount;i++){
            for(int j=0;j<rowCount;j++){
                if(arr[i][j]==true and (j-i+1)>maxLength){
                    maxLength=j-i+1;
                    substring=s.substr(i,j-i+1);
                }
            }
        }

        // delete the array
        for(int i = 0; i < rowCount; ++i) {
            delete [] arr[i];
        }
        delete [] arr; 

        return substring;
    }
};

class Solution {
    // valid way of filling array 
    for(int l = 1; l < N; l++) {
        for(int i = 0; i < N - l; i++) {
            int j = i + l;
            // when there are only 2 chars, just check the first and last chars
            if(j - i + 1 == 2)
                dp[i][j] = s[i] == s[j];
            else {
                // current s[i:j] can only be palindromic iff
                // first and last chars are same and the substring s[i+1:j-1]
                // is also palindromic
                dp[i][j] = (s[i] == s[j] && dp[i+1][j-1]) == true;
            }
            // update max length
            if(dp[i][j] && (j - i + 1) > max_len) 
                max_len = j - i + 1, start = i;
        }
    }
    
};

int main(){   
    int t;
    // cin>>t;
    string str;
    cin>>str;
    Solution* solution = new Solution();
    cout<<solution->longestPalindrome(str)<<endl;

    // while(t>0){
    //     cin>>str;
    //     cout<<solution->longestPalindrome(str)<<endl;
    //     t--;
    // }
}