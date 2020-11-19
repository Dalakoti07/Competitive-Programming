//User function template for C++

// arr : given array
// l : starting index of the array i.e 0
// r : ending index of the array i.e size-1
// k : find kth smallest element and return using this function

// classic partition code
int partition(int arr[],int l,int r){
    //using 2 pointer technique which uses the fact that i is index where next elem less than pivot would be placed 
    int pivotElem= arr[r];
    
    int i=l;
    for(int j=l;j<r;j++){
        if(arr[j]<pivotElem){
            swap(arr[i],arr[j]);
            i++;
        }
    }
    swap(arr[i],pivotElem);
    // atlast we have all elem less than = to pivot would be to left of i and all greater than pivot would to i's right 
    return i;
}

int kthSmallest(int arr[], int l, int r, int k) {
    //code here
    cout<<"k : "<<k<<" l: "<<l<<" r: "<<r<<endl;
    if (k > 0 && k <= r - l + 1) { 
        int position = partition(arr,l,r);
        cout<<"position is :"<<position<<endl;
        if(position-1==k-1){
            return arr[k];
        }else if(k-1<position-1){
            return kthSmallest(arr,l,position-1,k);
        }else{
            return kthSmallest(arr,position+1,r,k-position+l-1);
        }
    }else{
        return INT_MAX;
    }
}