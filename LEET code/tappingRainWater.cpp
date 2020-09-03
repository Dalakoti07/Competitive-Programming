class Solution {
public:
    int trap(vector<int>& height) {
        int ans=0,n=height.size();
        vector<int> onLeft(n),onRight(n);
        // onleft[i] means max on left of i
        // onright[i] means max on right of i
        onLeft[0]=height[0];
        onRight[n-1]=height[n-1];
        for(int i=1;i<n;i++){
            onLeft[i]=max(onLeft[i-1],height[i]);
        }
        for(int i=n-2;i>=0;i--){
            onRight[i]=max(onRight[i+1],height[i]);
        }
        // calculate
        for(int i=0;i<n;i++){
            ans+=min(onLeft[i],onRight[i])-height[i];
        }
        return ans;
    }
};