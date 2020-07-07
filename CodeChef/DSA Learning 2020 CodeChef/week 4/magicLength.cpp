// sort the N points and O(n) to find which 3 consecutive numbers form the least sum

#include<bits/stdc++.h>
using namespace std;


double calDistance(pair<double,double> p1,pair<double,double> p2,pair<double,double> p3){
    // cout<<"\n calculating distance between "<<p1.first<<" "<<p1.second<<" and "<<p2.first<<" "<<p2.second<<" and "<<p3.first<<" "<<p3.second;
    double one =sqrt((p1.first-p2.first)*(p1.first-p2.first)+(p1.second-p2.second)*(p1.second-p2.second));
    double two =sqrt((p2.first-p3.first)*(p2.first-p3.first)+(p2.second-p3.second)*(p2.second-p3.second));
    double three =sqrt((p1.first-p3.first)*(p1.first-p3.first)+(p1.second-p3.second)*(p1.second-p3.second));
    // cout<<" and distance is "<<one+two+three<<"\n";
    return one+two+three;
}

bool comparator(pair<double,double> p1,pair<double,double> p2){
    // if(p1.first==p2.first){
    //     return p1.second<p2.second;
    // }
    return p1.first<p2.first;
}

int main(){
    int t,i=0;
    cin>>t;
    while(i<t){
        int n;
        double a,b;
        cin>>n;
        vector<pair<double,double>> points(n);
        for(int i=0;i<n;i++){
            cin>>a>>b;
            points[i]={a,b};
        }
        sort(points.begin(),points.end(),comparator);
        double ans =INT_MAX;
        for(int i=0;i<n-2;i++){
            // points[i], points[i+1], points[i+2]
            ans=min(ans,calDistance(points[i],points[i+1],points[i+2]));
        }
        cout<<fixed<<setprecision(10)<<"Case "<<i+1<<": "<<ans<<" \n";
        i++;
    }
}