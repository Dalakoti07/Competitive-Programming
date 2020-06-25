class Solution {
public:
    int findMinFibonacciNumbers(int k) {
        int ans=0;
        vector<int> fib=vector<int>{1,1};
        long a=1,b=1;
        for(; ;){
            long curr=a+b;
            // cout<<curr<<" ";
            if(curr>k) break;
            fib.push_back(curr);
            long temp=a;
            a=curr;
            b=temp;
        }

        auto itr=lower_bound(fib.begin(),fib.end(),k);
        if(fib[itr - fib.begin()] == k) return 1;
        for(int i=itr - fib.begin();i>=0 and k>0;i--){
            if(fib[i]<=k) {
                k-=fib[i];
                ans++;
            }
        }
        return ans;
    }
};