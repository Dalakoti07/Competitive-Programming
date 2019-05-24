#include <bits/stdc++.h>
using namespace std;


int kadanes(int* arr,int start,int end)
{
  int max_sum=INT_MIN,max_so_far=0;
  for(int i=start;i<end;i++)
  {
    max_so_far=max_so_far+arr[i];
    if(max_so_far>max_sum)
      max_sum=max_so_far;
    if(max_so_far<0)
      max_so_far=0;
  }
  return max_sum;
}
int go(int arr[][100],int m,int n)
{
  //select the start and end column appropriately accordingly
  int max_sum=INT_MIN;
  for(int i=0;i<n;i++)
  {
    int vertical_arr_sum[m]={0};
    for(int x=0;x<m;x++)
      vertical_arr_sum[x]=arr[x][i];
    int answer=kadanes(vertical_arr_sum,0,m);
    if(answer>max_sum)
        max_sum=answer;
    for(int j=i+1;j<n;j++)
    {
      for(int z=0;z<m;z++)// adding the extra column
      	vertical_arr_sum[z]+=arr[z][j];
      answer=kadanes(vertical_arr_sum,0,m);
      if(answer>max_sum)
        max_sum=answer;
    }
  }
  return max_sum;
}

int main()
{
  	int m,n;
  	cin>>m>>n;
  	
  	int arr[m][100];
  for(int i=0;i<m;i++)
    for(int j=0;j<n;j++)
      cin>>arr[i][j];
  cout<<go(arr,m,n);
    return 0;
}
