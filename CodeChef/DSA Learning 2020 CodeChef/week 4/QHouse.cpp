#include<bits/stdc++.h>
using namespace std;

int main(){
    int x,y;
    // first find area of triangle
    // for that calculate height and width of it
    int start =0, end =int(1e3),mid;
    string result;
    // find width of square, BS on x axis
    y=0;
    int halfwidth;
    while(start<=end){
        x=(start+end)/2;
        mid=x;
        cout<<"? "<<x<<" "<<y<<"\n";
        fflush(stdout);

        cin>>result;
        if(result=="YES"){
            start=mid+1;
            halfwidth=mid;
        }else{
            end=mid-1;
        }
    }
    int areaOfSquare=pow(halfwidth*2,2);
    // cout<<" \nWIDTH OF SQUARE : "<<halfwidth<<" area :"<<areaOfSquare<<"\n";
    y=halfwidth*2;
    // find the end of trianngle along y axis
    start=y;
    end=int(1e3);
    x=0;
    while(start<=end){
        mid=(start+end)/2;
        cout<<"? "<<x<<" "<<mid<<"\n";
        fflush(stdout);

        cin>>result;
        if(result=="YES"){
            start=mid+1;
            y=mid;
        }else{
            end=mid-1;
        }
    }
    int heightOfTriangle = y-(halfwidth*2);
    // cout<<" height of triangle "<<heightOfTriangle<<" \n";
    // find the edge of triangle which is parallel to x axis
    start=0,end=int (1e3);
    y=halfwidth*2;
    while(start<=end){
        mid=(start+end)/2;
        cout<<"? "<<mid<<" "<<y<<"\n";
        fflush(stdout);

        cin>>result;
        if(result=="YES"){
            start=mid+1;
            x=mid;
        }else{
            end=mid-1;
        }
    }
    int areaOfTriangle= heightOfTriangle*x;
    // cout<<" area of trai "<<areaOfTriangle<<"\n";
    fflush(stdout);
    cout<<"! "<<areaOfTriangle+areaOfSquare<<endl;
}