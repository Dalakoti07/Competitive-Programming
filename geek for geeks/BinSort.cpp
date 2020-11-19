// sorting 0 and 1 in one pass
void binSort(int A[], int N)
{
   //Your code here
   //left would contain all 0s to its left and right would contain all 1s to its right
   int left=0,right=N-1;
   while(left<right){
       //cover all 0s
        while(A[left]==0 and left<right)
            left++;
        //cover all 1s
        while(A[right]==1 and left<right)
            right--;
        
        if(left<right){
            if(A[left]==1 and A[right]==0){
                swap(A[left],A[right]);
                left++;
                right--;
            }    
        }
   }
   
   
   /**************
    * No need to print the array
    * ************/
}