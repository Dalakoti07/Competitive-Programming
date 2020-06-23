class Solution {
public:
    static bool comparator(pair<int,int>& a,pair<int,int>& b){
        return a.first<b.first;
    }
    int largestSumAfterKNegations(vector<int>& A, int K) {
        // greed is that we will negate the min number always
        vector<pair<int,int>> AWithIndex;
        for(int i=0;i<A.size();i++){
            AWithIndex.push_back(make_pair(A[i],i));
        }

        sort(AWithIndex.begin(),AWithIndex.end(),comparator);// sort as per value

        int a=0;
        for(int i=1;i<=K;i++){
            int value = AWithIndex[a].first;
            value= -1* value;
            A[AWithIndex[a].second]=value;
            // there is an edge case ,what if [a+1] is out of bound
            if(value> AWithIndex[a+1].first){// if negated value is > sorted array value, means min is min no more we have better min ahead
                a++;
            }else{
                AWithIndex[a].first=value;
            }
        }
        int sumOfAll =0;
        for(int i=0;i<A.size();i++){
            sumOfAll+=A[i];
        }
        return sumOfAll;
    }

    // A better implementation and using inbuilt dsa
    /*
        int largestSumAfterKNegations(vector<int>& A, int K) {
            priority_queue<int, vector<int>, greater<int>> pq(A.begin(), A.end());
            while (K--) {
                int x = pq.top();
                pq.pop();

                pq.push(-1 * x);
            }
            int res = 0;
            while (!pq.empty()) {
                res += pq.top();
                pq.pop();
            }
            return res;
        }
    */
};