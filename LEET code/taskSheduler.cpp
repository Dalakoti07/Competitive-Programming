class Solution {
public:
    void traverseTheHeap(vector<pair<int,char>>& lheaps){
        for(auto h: lheaps){
            cout<<h.second<<" "<<h.first<<endl;
        }
        cout<<endl;
    }

    int leastInterval(vector<char>& tasks, int n) {
        // we will use the max heaps which will contain pair<int,char>
        // greedily pick the top element and then do the calculation 
        map<char,int> m;
        for(int i=0;i<tasks.size();i++){
            m[tasks[i]]++;
        }
        // make heap
        vector<pair<int,char>> lheaps;
        for(auto mi:m){
            lheaps.push_back({mi.second,mi.first});
        }
        make_heap(lheaps.begin(),lheaps.end());

        int timeUnits=0;
        while(lheaps.size()>1){
            pair<int,char> topElem=lheaps.front();
            pop_heap(lheaps.begin(),lheaps.end());
            lheaps.pop_back();
            int popOperations=min(n,(int)lheaps.size());
            timeUnits++;

            // elements which are added 
            vector<pair<int,char>> elemsUsed;
            for(int i=1;i<=popOperations;i++){
                pair<int,char> popedElem=lheaps.front();
                elemsUsed.push_back(popedElem);
                pop_heap(lheaps.begin(),lheaps.end());
                lheaps.pop_back();
                timeUnits++;
            }

            // pushing the useful elemes back
            for(int i=0;i<elemsUsed.size();i++){
                pair<int,char> popedElem=elemsUsed[i];
                if(popedElem.first>1){
                    lheaps.push_back({popedElem.first-1,popedElem.second});
                    push_heap(lheaps.begin(),lheaps.end());
                }
            }

            // push back the top elem if its freq is greater than 1
            if(topElem.first>1){
                lheaps.push_back({topElem.first-1,topElem.second});
                push_heap(lheaps.begin(),lheaps.end());
            }

            if(popOperations<n and lheaps.size()>0){
                timeUnits+=n-popOperations;
            }
                        
        }
        if(lheaps.size()==1){
            pair<int,char> elem=lheaps.front();
            timeUnits+=(elem.first-1)*(n+1);
            timeUnits++;
        }
        return timeUnits;
    }
};