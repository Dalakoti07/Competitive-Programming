vector<vector<int> > fourSum(vector<int> &arr, int k) {
    int i,j,left,right,n=arr.size();
    vector<vector<int>> answer= vector<vector<int>>();
    sort(arr.begin(),arr.end());
    for(i=0;i<n-3;i++){
        for(j=i+1;j<n-2;j++){
            left=j+1;
            right=n-1;
            while(left<right){
                if(arr[i]+arr[j]+arr[left]+arr[right]==k){
                    auto temp=vector<int>{arr[i],arr[j],arr[left],arr[right]};
                    answer.push_back(temp);  
                    left++;
                    right--;
                }else if(arr[i]+arr[j]+arr[left]+arr[right]<k)
                    left++;
                else
                    right--;
            }
        }
    }
    // cout<<answer.size();
    // answer.clear();
    return answer;
}