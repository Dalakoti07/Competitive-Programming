#include<bits/stdc++.h>
using namespace std;
// O(n^2) complexity
// class Solution {
// public:
//     int maxArea(vector<int>& height) {
//         int answer =0;
//         int size= height.size();
//         for(int i=0;i<size;i++){
//             for(int j=i+1; j<size;j++){
//                 if(answer < (j-i)*min(height[i],height[j]) ){
//                     answer=(j-i)*min(height[i],height[j]);
//                 }
//             }
//         }
//         return answer;
//     }
// };

class Solution {
    public:
    int maxArea(vector<int>& height){
        int answer=0;
        for(int i=0,j=height.size()-1;i<j;){
            if(answer< (min(height[i],height[j]) * (j-i) )){
                answer=min(height[i],height[j]) * (j-i);
            }
            if(height[i]<height[j]){
                i++;
            }else{
                j--;
            }
        }
        return answer;
    }
};

int main(){
    int t;
    cin>>t;
    Solution* solution = new Solution();
    while(t>0){
        int n,x;
        cin>>n;
        vector<int> array;
        while(n){
            cin>>x;
            array.push_back(x);
            n--;
        }
        cout<<solution->maxArea(array)<<endl;
        t--;
    }
}