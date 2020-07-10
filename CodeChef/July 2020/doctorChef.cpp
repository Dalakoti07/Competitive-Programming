#include<bits/stdc++.h>
using namespace std;

int tellTheDays(long long population,int cures){
    int dayCount=0;
    long long currentPopulation=population;
    long long curesCount=min((long long)cures,currentPopulation),peopleCured;
    while(currentPopulation!=0){
        dayCount++;
        peopleCured=curesCount;
        currentPopulation=min(population,(currentPopulation-peopleCured)*2);
        curesCount=min( 2*peopleCured,currentPopulation);
    }
    return dayCount;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        bool allAreEqual=true;
        int n,x,last;
        long long cures;
        cin>>n>>cures;
        multiset<int, greater <int>> arr;
        cin>>x;
        arr.insert(x);
        last=x;
        for(int i=1;i<n;i++){
            cin>>x;
            arr.insert(x);

            if(last!=x)
                allAreEqual=false;
            last=x;
        }
        long long dayCount=0;
        if(allAreEqual){
            dayCount=tellTheDays(*(arr.begin()),cures);
            cout<<dayCount+n-1<<"\n";
        }else{
            // sort(arr.begin(),arr.end()); ,its sorted
            // starting with most populous country and feed all the countries on the way (which have requirement of cures <=curentcures)
            // do dayCount--, if country has been made corona free
            //, and atlast do dayCount + n-1;
            // handle edge cases, like etc
            

            cout<<dayCount<<"\n";
        }
    }
}