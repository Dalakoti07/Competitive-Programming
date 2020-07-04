#include<bits/stdc++.h>
using namespace std;

bool lexicalCompare(string a,string b){
    // cout<<" a : "<<a<<" b: "<<b<<"\n";
    // return true if a is lexical smaller than b 
    if(b.length()>a.length()) return false;
    int bound=min(a.length(),b.length());
    for(int i=0;i<bound;i++){
        if(a[i]<b[i]) return true;
        if(a[i]>b[i]) return false;
    }
    return false;
}

int main(){
    // nested maps gave TLE like map<str, map<str,int>>
    int chefsCount,MailsCount;
    string chefName,countryName;
    cin>>chefsCount>>MailsCount;

    map<string,string> chefToCountry;
    map<string,int> CountryToPoints,ChefToPoints;
    for(int i=0;i<chefsCount;i++){
        cin>>chefName>>countryName;
        chefToCountry[chefName]=countryName;
        if(CountryToPoints.count(countryName)==0)
            CountryToPoints[countryName]=0;
        ChefToPoints[chefName]=0;
    }
    for(int i=0;i<MailsCount;i++){
        cin>>chefName;
        ChefToPoints[chefName]+=1;
        CountryToPoints[chefToCountry[chefName]]+=1;
    }
    // find max in shefTopoints and countrytopoints
    int maxPointsByCountry=0;
    for(auto m: CountryToPoints){
        if(m.second> maxPointsByCountry){
            maxPointsByCountry=m.second;
            countryName=m.first;
        }
    }
    int maxPointsByChef=0;
    for(auto m: ChefToPoints){
        if(m.second>maxPointsByChef){
            maxPointsByChef=m.second;
            chefName=m.first;
        }
    }
    cout<<countryName<<endl<<chefName<<endl;
}