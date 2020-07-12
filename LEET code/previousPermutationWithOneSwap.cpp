class Solution {
public:
    // https://www.nayuki.io/page/next-lexicographical-permutation-algorithm
    vector<int> prevPermOpt1(vector<int>& a) {
     if(is_sorted(a.begin(),a.end()))return a;
        int n=a.size();
        int ind;
        for(int i=0;i<n-1;i++)
            if(a[i]>a[i+1])ind=i;
        int ind1=ind+1,no=a[ind+1],diff=a[ind]-a[ind+1];
        for(int j=ind+1;j<n;j++)
        {
            if(a[j]<a[ind] and a[ind]-a[j]<diff)
                diff=a[ind]-a[j],ind1=j;
        }
        swap(a[ind],a[ind1]);
        // reverse(a.begin()+ind+1,a.end());
        return a;
    }
};