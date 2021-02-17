#include <vector>
using namespace std;

int firstDuplicateValue(vector<int> arr) {
	map<int,int> m;// {elem,index}
	for(int i=0;i<arr.size();i++){
		if(m.find(arr[i])!=m.end())
			return arr[i];
		else
			m[arr[i]]=i;
	}
	return -1;
}
