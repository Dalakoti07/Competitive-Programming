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
        multiset<int> arr;
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
            auto lastItr=arr.end();
            lastItr--;
            int largest=*(lastItr);
            arr.erase(lastItr);
            int optionOne =tellTheDays(largest,cures);
            optionOne+=n-1;
            int optionTwo=0;
            long long currentPopulation=largest;
            long long curesCount=min((long long)cures,currentPopulation),peopleCured;
            int i=1;
            optionTwo++;
            // cout<<" end of day 1\n";
            currentPopulation=min((long long)largest,(currentPopulation-curesCount)*2);
            curesCount*=2;
            while(currentPopulation!=0){
                if(arr.empty()){
                    optionTwo+=tellTheDays(largest,curesCount);
                    break;
                }
                auto itr=arr.lower_bound(curesCount);
                // cout<<"finding lowerBound for "<<curesCount<<" and *itr is "<<*itr<<"\n";
                if(itr==arr.end()){
                    itr--;
                }
                if(*itr>=curesCount/2 and *itr!=largest ){
                    // cout<<" got into the loop ";
                    // optionTwo--;
                    if(itr!=arr.begin()){
                        auto oneBack=--itr;
                        if((*oneBack)>=curesCount/2 and *oneBack<=curesCount){
                            // cout<<"nested valid move and completed this country "<<*oneBack<<"\n";
                            curesCount=2*(*oneBack);
                            i++;
                            // cout<<" end of day "<<i<<"\n";
                            arr.erase(oneBack);
                            // i++;
                            continue;
                        }
                        itr++;
                    }
                    if(*itr<=curesCount){
                        // cout<<" was valid move and completed this country "<<*itr<<"\n";
                        curesCount=2*(*itr);
                        i++;
                        // cout<<" end of day "<<i<<"\n";
                        arr.erase(itr);
                        // i++;
                        continue;
                    }

                }
                peopleCured=curesCount;
                currentPopulation=min((long long)largest,(currentPopulation-peopleCured)*2);
                curesCount=min( 2*peopleCured,currentPopulation);
                optionTwo++;
                i++;
                // cout<<"end of day : "<<i<<" -> pop: "<<currentPopulation<<", cures ava for next country :"<<curesCount<<"\n";
            }
            // cout<<" count after this "<<optionTwo<<"\n";
            optionTwo+=n-1;
            dayCount=min(optionOne,optionTwo);
            cout<<dayCount<<"\n";
        }
    }
}