int transitionPoint(int arr[],int n)
{
	// by brute force it would take n time, in one second it is possible
	// in case of TLE binary search can help
	for(int i=0;i<n;i++)
		if(arr[i]==1)
			return i;
}