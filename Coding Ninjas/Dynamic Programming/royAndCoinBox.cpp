#include <bits/stdc++.h>
using namespace std;
void print(int arr[],int n)
{
    for(int i=1;i<n;i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}
int main()
{
    int n,m,q,l,r;
    cin>>n>>m;
    int left[n+1]={0},right[n+1]={0};
    for(int i=1;i<=m;i++)
    {
        cin>>l>>r;
        left[l]++;
        right[r]++;
    }
    cin>>q;
    //making dp array which tells how many balls in ith boc
    int dp_coins_in_boxes[n+1]={0};
    dp_coins_in_boxes[1]=left[1];
    for(int i=2;i<=n;i++)
        dp_coins_in_boxes[i]=left[i]-right[i-1]+dp_coins_in_boxes[i-1]; 
    //print(dp_coins_in_boxes,n+1);
    
    // we have to do reverse given balls, we are to tell number of boxes
    int dpbheib[n+1]={0};// dp of boxes having exact i balls, see here that from above dp to final dp it is complicated to get there thus we made an intermediate dp and 
   for(int i=1;i<=n;i++)
   {
       dpbheib[dp_coins_in_boxes[i]]++;
   }
    //print(dpbheib,n+1);
    // now the final dp array which tells that given balls ,count the at least boxes which contain them
    int dp_final[n+1]={0};
    dp_final[n]=dpbheib[n];
    for(int i=n-1;i>=1;i--)// traversing from back of the dp array becoz last element has no dependecies
    {
        dp_final[i]=dp_final[i+1]+dpbheib[i];
    }
    // you could have used the same dp array
    //print(dp_final,n+1);
    
    for(int i=1;i<=q;i++)
    {
        cin>>n;
        cout<<dp_final[n]<<endl;
    }
    return 0;
}
