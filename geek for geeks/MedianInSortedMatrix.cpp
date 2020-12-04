int median(vector<vector<int>> &arr, int r, int c){
    // awesome question bro and use-case of BS is awesome 
    int Max=INT_MIN,Min=INT_MAX;
    for(int i=0;i<r;i++){
        Max=max(arr[i][c-1],Max);
        Min=min(arr[i][0],Min);
    }
    int expectedCount=((r*c)+1)/2;
    int mid;
    while(Min<Max){
        mid=Min+(Max-Min)/2;
        int elemsLessThanMid=0;
        for(int i=0;i<r;i++)
            elemsLessThanMid+=upper_bound(arr[i].begin(),arr[i].begin()+c,mid)-arr[i].begin();
        if(elemsLessThanMid<expectedCount)
            Min=mid+1;
        else
            Max=mid;
    }
    return Max;
}