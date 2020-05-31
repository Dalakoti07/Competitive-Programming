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

// another solution is longestplaindromesubstring of string s, is common substring between s and s'
class Solution {
public:
    string longestPalindrome(string s) {
        
    }
};

int main(){   

    int t;
    cin>>t;
    string str;
    Solution* solution = new Solution();
    while(t>0){
        cin>>str;
        cout<<solution->longestPalindrome(str)<<endl;
        t--;
    }
}