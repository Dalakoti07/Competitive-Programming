#include <bits/stdc++.h>
using namespace std;
void print(int arr[],int n)
{
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}
int main()
{
    int r,c,m,x;
    cin>>r>>c;
    int arr1[c],arr2[c],dp1[c]={0},dp2[c]={0},dpf[r]={0};
    for(int j=0;j<c;j++)
            cin>>arr1[j];
    for(int j=0;j<c;j++)
            dp1[j]=0;
    dpf[0]=0;
    for(int i=1;i<r;i++)
    {
        if(i%2==1)
        {
            for(int j=0;j<c;j++)
            {
                cin>>arr2[j];
                if(arr2[j]>=arr1[j])
                    dp2[j]=dp1[j];
                else
                    dp2[j]=i;
            }
            //put the minimum in dpf
            int min=INT_MAX;
            for(int i=0;i<c;i++)
                if(dp2[i]<min)
                    min=dp2[i];
            dpf[i]=min;
           // print(dp2,c);
        }        
        else
        {
            for(int j=0;j<c;j++)
            {
                cin>>arr1[j];
                if(arr1[j]>=arr2[j])
                    dp1[j]=dp2[j];
                else
                    dp1[j]=i;
            }
            int min=INT_MAX;
            for(int i=0;i<c;i++)
                if(dp1[i]<min)
                    min=dp1[i];
            dpf[i]=min;
            //print(dp1,c);
        }
    }
    cin>>m;
   // print(dpf,r);
    for(int i=1,x,y;i<=m;i++)
    {
        cin>>x>>y;
        x--;
        y--;
        if(x>=dpf[y])
            cout<<"Yes\n";
        else
            cout<<"No\n";
    }
    return 0;
}
