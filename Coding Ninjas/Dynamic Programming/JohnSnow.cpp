#include <bits/stdc++.h>
using namespace std;

int *go(int* arr,int n,int x)
{
    int* local_arr=new int[1024];
    int new_index;
    int elements_seen=0;
    for(int i=0;i<1024;i++)
    {
        new_index=i^x;
        if(arr[i]!=0)
        {
            if(elements_seen%2==0 and arr[i]%2==1)
            {
                local_arr[new_index]+=(arr[i]/2+1);    // giving n/2 +1 elements
                local_arr[i]+=(arr[i]/2);// giving remaining elements
            }
            else if(elements_seen%2 ==1 and arr[i]%2==1)
            {
                local_arr[new_index]+=(arr[i]/2);
                local_arr[i]+=(arr[i] - (arr[i]/2));
            }
            else //if(elements_seen%2==0 and arr[i]%2==0)
            {
                local_arr[new_index]+=(arr[i]/2);
                local_arr[i]+=(arr[i]/2);
            }
            elements_seen+=arr[i];
        }
    }
    //copy back the array, or retunr the new array
    return local_arr;
}

int main()
{
    int n,k,x,a;
    cin>>n>>k>>x;
    int* arr=new int[1024]();
    for(int i=0;i<n;i++)
    {
        cin>>a;
        arr[a]++;
    }
    
    for(int j=1;j<=k;j++)
    {
        arr=go(arr,n,x);
    }
    int min,max;
    for(int i=0;i<1024;i++)
        if(arr[i]!=0)
        {min=i;break;}
// find the maximum
    for(int i=1023;i>=0;i--)
        if(arr[i]!=0)
        {max=i;break;}
    cout<<max<<" "<<min;
    return 0;
}
