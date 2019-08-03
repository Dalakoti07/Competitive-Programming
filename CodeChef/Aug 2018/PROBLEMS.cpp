// partially accepted
// most difficult part was to understand the question
#include<bits/stdc++.h>
using namespace std;

bool cmp2(pair<int,int> &a, pair<int,int> &b) {
  if (a.first == b.first) {
    return a.second < b.second;
  }
  return a.first < b.first;
}

int arr1[30],arr2[30];
int main(){
	int p,s;
	cin>>p>>s;
	vector<pair<int,int>> problemsComplexity;
	vector<pair<int,int>> subtasks;
	for(int i=0;i<p;i++){
		for(int x=0;x<s;x++)
			cin>>arr1[x];
		for(int y=0;y<s;y++)
			cin>>arr2[y];
		for(int j=0;j<s;j++)
			subtasks.push_back(make_pair(arr1[j],arr2[j]));
		sort(subtasks.begin(),subtasks.end());
		// cout<<"The subtasks after sorting are \n";
		// for(int i=0;i<subtasks.size();i++)
		// 	cout<<subtasks[i].first<<" "<<subtasks[i].second<<endl;

		// cout<<endl;
		// counting the n, as per question,it would take SS time
		int count=0;
		for(int z=0;z<subtasks.size()-1;z++){
			for(int j=z+1;j<subtasks.size();j++)
				if(subtasks[z].second>subtasks[j].second)
					{count++;
						// cout<<subtasks[z].second<<" greater than "<<subtasks[j].second<<endl;
					}
		}
		subtasks.clear();
		problemsComplexity.push_back(make_pair(count,i));
	}
	sort(problemsComplexity.begin(),problemsComplexity.end(),cmp2);
	for(int i=0;i<p;i++){
		cout<<problemsComplexity[i].second+1<<endl;
	}
}