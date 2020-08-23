class Solution {
public:
    vector<int> allFibs;
    void generateAllFibs(){
        long long i=1,idx=2;
        allFibs.push_back(i);
        allFibs.push_back(i);
        while((long long)i<=(int)1e9){
            i=(long long)allFibs[idx-1]+(long long)allFibs[idx-2];
            idx++;

            allFibs.push_back(i);
        }
    }
    int count=0;
    // rec function and we are using greedy approach
    void countMin(int k){
        if(k<=0) return;
        auto a=lower_bound(allFibs.begin(),allFibs.end(),k);
        if(*a == k){
            count++;
            return ;
        }else{
            if(a!=allFibs.begin()){
                a--;
                count++;
                countMin(k-(*a));
            }else{
                count++;
                countMin(k-1);
            }
        }
    }

    int findMinFibonacciNumbers(int k) {
        // cout<<" func called ";
        generateAllFibs();
        countMin(k);
        return count;
    }
};