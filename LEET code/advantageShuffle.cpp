class Solution {
public:
    vector<int> advantageCount(vector<int>& A, vector<int>& B) {
        // sort A and then for each element of B find element greater 
        sort(A.begin(),A.end());
        vector<int> ans;

        for(auto i:B){
            auto itr=upper_bound(A.begin(),A.end(),i);
            if(itr==A.end())
                ans.push_back(-1);
            else{
                ans.push_back(*itr);
                A.erase(itr);
            }
        }
        
        // replace the item which marked as -1 
        int idx=0;
        int n =ans.size();
        for(int i=0;i<n;i++){
            if(ans[i]==-1){
                ans[i]=A[idx];
                idx++;
            }
        }

        return ans;
    }
};