long staircase(int n){
    /*  Don't write main().
     *  Don't read input, it is passed as function argument.
     *  Return output and don't print it.
     *  Taking input and printing output is handled automatically.
     */
    long int* arr=new long int[n+3];
  	arr[1]=1;
  	arr[2]=2;
  	arr[3]=4;
  	for(int i=4;i<=n;i++)
      arr[i]=arr[i-1]+arr[i-2]+arr[i-3];// you wont do arr[i-1]+2*arr[i-2]+4*arr[i-3] as when you are in i-3 then going to i would have 4 possiblities ,but those are counted in
  										// in i-2 and i-1 and putting 4 in coeffecient ,does overcounting
    return arr[n];
}
