#include<bits/stdc++.h>
using namespace std;

int main()
{
	int test;
	cin>>test;
	while(test--)
	{
		int n;
		cin>>n;
		int arr[n],dp[n];
		for(int i=0;i<n;dp[i]=arr[i],i++)
			cin>>arr[i];
		
		vector<int> answer,last,secondLast,temp;
		bool answ_last=true;
		if(n==1)
			cout<<arr[0];
		else if(n==2)
			cout<<max(arr[0],arr[1]);
		else
		{
			// code to deal with third element
			//if(arr[0]+arr[2]>arr[2] and arr[0]+arr[2]>arr[0] and arr[])
			last.push_back(1);
			secondLast.push_back(0);
			for(int i=2;i<n;i++)
			{
				if(dp[i]+dp[i-2]>dp[i] and dp[i]+dp[i-2]>dp[i-1])
					{
						dp[i]=dp[i]+dp[i-2];
						secondLast.push_back(i);
						// cout<<"the situation is last vec";
						//  for(int i:last)
						// 	cout<<arr[i]<<" ";
						//  cout<<endl;
						// cout<<"the situation is second last vec";
						//  for(int i:secondLast)
						// 	cout<<arr[i]<<" ";
						//  cout<<endl;
						answ_last=false;
					}
				else if(dp[i-1]>dp[i])
					{
						dp[i]=dp[i-1];
						answ_last=true;
						secondLast=last;
						// cout<<"the situation is last vec";
						//  for(int i:last)
						// 	cout<<arr[i]<<" ";
						//  cout<<endl;
						// cout<<"the situation is second last vec";
						//  for(int i:secondLast)
						// 	cout<<arr[i]<<" ";
						//  cout<<endl;
					}
				else
				// 	//...clear the previous record dp[i] is greater than all....
				 	{secondLast.clear();last.clear();secondLast.push_back(i);last.push_back(i);}
				temp=last;
				last=secondLast;
				secondLast=temp;
			}
			temp=last;
			last=secondLast;
			secondLast=temp;	
			// cout<<"sum is "<<dp[n-1]<<endl;
			if(answ_last)
				for(int i=last.size()-1;i>=0;i--)
				{if(arr[last[i]]!=0)
					cout<<arr[last[i]];}
			else
				for(int i=secondLast.size()-1;i>=0;i--)
				{if(arr[secondLast[i]]!=0)
				    cout<<arr[secondLast[i]];}
		}
		cout<<endl;
	}
}