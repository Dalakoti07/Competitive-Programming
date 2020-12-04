int rowWithMax1s(vector<vector<int> > arr, int n, int m) {
    int idx=-1,max1=INT_MIN;
    bool found=false;
    for(int i=0;i<n;i++){
        int ones=upper_bound(arr[i].begin(),arr[i].end(),0)-arr[i].begin();
        ones=m-ones;
        if(ones>0)
            found=true;
        //cout<<"ones in row: "<<i+1<<" are "<<ones<<endl;
        if(ones>max1){
            max1=ones;
            idx=i;
        }
    }
    if(found)
        return idx;
    else
        return -1;
    // complexity is nlogm
}