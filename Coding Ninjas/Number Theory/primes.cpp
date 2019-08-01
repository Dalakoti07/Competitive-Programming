// seive method
#include<bits/stdc++.h>
using namespace std;
bool arr[int(1e6)];
bool isPrime(int x)
{
    if(x==2)
        return true;
    for(int i=2;i<=sqrt(x);i++)
        if(x%i==0)
            return false;
    return true;
}

void preCompute()
{
	for(int i=1;i<int(1e6);i++)
		arr[i]=true;
	for(int i=2;i<=sqrt(1e6);i++)
	{
		if(arr[i]==false)
			continue;
		for(int j=i*i;j<=int(1e6);j+=i)
		{
			arr[j]=false;
		}
	}
}

int main(){
	// Write your code here
    int n,count=0;
    preCompute();
    cin>>n;
    for(int i=2;i<=n;i++)
    {
        //cout<<arr[i]<<" ";
        if(arr[i])
        	count++;
    }
    cout<<count;
	return 0;
}