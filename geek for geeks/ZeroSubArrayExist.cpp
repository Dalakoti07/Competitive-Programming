bool subArrayExists(int arr[], int n){
    //Your code here
    int prefixSum[n]={0};
    prefixSum[0]=arr[0];
    for(int i=1;i<n;i++){
        prefixSum[i]=arr[i]+prefixSum[i-1];
    }
    map<int,int> mappy;
    for(int i=0;i<n;i++){
        mappy[prefixSum[i]]++;
    }
    for(auto m:mappy){
        if(m.first==0)
            return true;
        if(m.second>=2)
            return true;
    }
    return false;
}