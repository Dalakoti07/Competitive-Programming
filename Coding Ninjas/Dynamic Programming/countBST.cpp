int countBST( int n)
{
  /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return output and don't print it.
     * Taking input and printing output is handled automatically.
     */
    int arr[n+1]={0};
  arr[1]=1;
  arr[0]=1;
  arr[2]=2;
  int mody=pow(10,9)+7;
  for(int i=3;i<=n;i++)
  {
    for(int j=1;j<=i;j++)
    { 
    	int temp=(int)(arr[j-1]*1l*arr[i-j])%mody;
      	arr[i]=(arr[i]+temp)%mody;
    }
  }
  return arr[n];
}
