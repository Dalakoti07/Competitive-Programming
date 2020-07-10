#include<bits/stdc++.h>
using namespace std;

int main() {
	vector<int> arr{80,80,80};
	cout<<"idx is "<<lower_bound(arr.begin(),arr.end(),80)-arr.begin();
	return 0;
}