class Solution {
public:
    void sortColors(vector<int>& nums) {
        int one=0,two=0,zero=0;
        // counting sort
        for(int n:nums){
            if(n==1)
                one++;
            else if(n==2)
                two++;
            else 
                zero++;
        }
        // fill the array
        for(int i=0;i<n;i++){
            if(zero){
                arr[i]=0;
                zero--;
            }else if(one){
                arr[i]=1;
                one--;
            }else{
                arr[i]=2;
                two--;
            }
        }
    }
};