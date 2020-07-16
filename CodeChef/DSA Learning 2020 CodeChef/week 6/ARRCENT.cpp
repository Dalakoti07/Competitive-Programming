/*
 *
 ********************************************************************************************
 * AUTHOR : Vijju123                                                                        *
 * Language: C++14                                                                          *
 * Purpose: -                                                                               *
 * IDE used: Codechef IDE.                                                                  *
 ********************************************************************************************
 *
 Comments will be included in practice problems if it helps ^^
 */
 
 
 
#include <iostream>
#include<bits/stdc++.h>
using namespace std;
 
int mod=pow(10,9)+7;
int main() {
	// your code goes here
	#ifdef JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
    #endif
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin>>t;
	while(t--)
	{
	    int i,n;
	    cin>>n;
	    int arr[n];
	    for(i=0;i<n;i++)cin>>arr[i];
	    int pre[100010]={0},suff[100010]={0};
	    for(i=1;i<=n;i++)
	    {
	        pre[i]=arr[i-1];
	        suff[n-i+1]=arr[n-i];
	    }
	    /**Simulate what happens when we do prefix sum 4 times.
	     * Take example of pre[5]. Let arr[1]=k. What is contribution of arr[1] after 4 prefix sum to pref[5]?
	     * First iteration-->pre[1]=pre[2]=pre[3]=pre[4]=pre[5]= k 
	     * Second iteration---> pre[2]=2k pre[3]=3k pre[4]=4k pre[5]=5k
	     * Coefficient of k in pre[i]=i.
	     * Third iteration ---> pre[2]=3k pre[3]=6k pre[4]=10k pre[5]=15k;
	     * Note now coefficient of k in pre[i]= (i+1)C2
	     * Fourth Iteration --->pre[2]=4k pre[3]=10k pre[4]=20k pre[5]=35k.
	     * Last prefix sum gave us the needed values
	     */
	    for(int j=1;j<=4;j++)
	    {
	        for(i=1;i<=n;i++)
	            pre[i]=(pre[i-1]+pre[i])%mod;
	        for(i=n;i>0;i--)
	            suff[i]=(suff[i+1]+suff[i])%mod;
	    }
	    
	    for(i=1;i<=n;i++)
	        cout<<(pre[i-1]+suff[i+1])%mod<<" ";cout<<endl;
	    
	}
	
	return 0;
}