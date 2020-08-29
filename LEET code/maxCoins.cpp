class Solution {
public:
    int maxCoins(vector<int>& piles) {
        vector<int> pSorted(piles);
        sort(pSorted.begin(),pSorted.end());
        make_heap(piles.begin(),piles.end());
        int n3=piles.size();
        if(n3==3) return pSorted[1];
        int i=0,ptrSorted=0;
        int mycoins=0;
        while(i!=n3){
            // greedily pick largest, second largest and smallest

            piles.front();
            pop_heap(piles.begin(),piles.end());
            piles.pop_back();
            i++;

            mycoins+=piles.front();
            pop_heap(piles.begin(),piles.end());
            piles.pop_back();
            i++;

            ptrSorted++;
            i++;
        }
        return mycoins;
    }
};