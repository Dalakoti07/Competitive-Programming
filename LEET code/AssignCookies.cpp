class Solution {
public:
    int findContentChildren(vector<int>& greedOfChildren, vector<int>& cookies) {
        // greedy approach is to use least powerful cake for least poweful demand from child and make him happy
        sort(greedOfChildren.begin(),greedOfChildren.end());
        sort(cookies.begin(),cookies.end());

        int count =0,i=0,j=0,n=greedOfChildren.size(),m=cookies.size();
        for(;i<n and j<m ;){
            if (greedOfChildren[i]<=cookies[j]){
                i++;
                j++;
                count++;
            }else if(cookies[j]<greedOfChildren[i]){
                j++;
            }
        }
        return count;
    }
};