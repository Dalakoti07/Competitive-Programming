ll findSubarray(vector<ll> arr, int n ) {
    // map[sum] stores starting index of all subarrays 
    unordered_map<int,vector<int>> mappy;
    
    int sum=0,count=0;
    // below vector contains all answers with index
    vector<pair<int,int>> answers;
    for(int i=0;i<arr.size();i++){
        sum+=arr[i];
        if(sum==0){
            // answers.push_back(make_pair(0,i));
            count++;
        }
        if(mappy.find(sum)!=mappy.end()){
            /*vector<int> temp=mappy[sum];
            for(auto it=temp.begin();it!=temp.end();it++){
                answers.push_back(make_pair((*it)+1,i));
            }*/
            count+=mappy[sum].size();
        }
        mappy[sum].push_back(i);
    }
    return count;
}