#include<bits/stdc++.h>
using namespace std;

bool isMonotonic(vector<int> arr) {
  // Write your code here.
	//check for non increasing
	if(arr.size()<=2)
		return true;
	int a=arr[0];
	bool isPossible=true;
	for(int i=1;i<arr.size();i++){
		if(arr[i]-a>0){
			isPossible=false;
			break;		
		}
		a=arr[i];
	}
	if(isPossible) return true;
	// check for non decreasing
	a=arr[0];
	isPossible=true;
	for(int i=1;i<arr.size();i++){
		//cout<<i<<"--"<<arr.size()<<endl;
		if(arr[i]-a<0){
			return false;
		}
		a=arr[i];
	}
	//cout<<"out";
  return true;
}

int main(){
    int t=1;
    while(t--){
        int n=1;
        vector<int> vec{-1,-5,-10,-1100,-1100,-1101,-1102,-9001};
        cout<<isMonotonic(vec)<<endl;
    }
}