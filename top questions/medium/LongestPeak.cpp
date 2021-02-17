#include<bits/stdc++.h>
using namespace std;

int longestPeak(vector<int> arr) {
  if(arr.size()==0)
		return 0;
  int length=0;
// 	finding all peaks in the array and their length and updating the corresponding peak to largest
	int i=1;
	while(i<arr.size()-1){
		if(arr[i]>arr[i-1] and arr[i]>arr[i+1]){
// 			find length of the peak whose top is arr[i]
			int l=1,curr=i-1;
// 			goto left
			while(arr[curr]<arr[curr+1] and curr>=0){
				l++;
				curr--;
			}
// 			goto right
			curr=i+1;
			while(arr[curr]<arr[curr-1] and curr<arr.size()){
				l++;
				curr++;
			}
			if(l>length){
					length=l;
			}
			// as elemes from [i+1,curr-1] are not peak by themselves they are part of peak
			i=curr;
		}else{
			i++;
		}
	}
  return length;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        n=1;
        vector<int> vec{1,3,2};
        for(int i=0;i<n;i++)
            cin>>vec[i];
        cout<<longestPeak(vec)<<endl;
    }
}